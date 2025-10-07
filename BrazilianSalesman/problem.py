"""The Brazilian Salesman problem class."""
from typing import Annotated, Iterable, Self

from algobattle.problem import Problem, InstanceModel, SolutionModel, minimize
from algobattle.util import BaseModel, Role, ValidationError
from algobattle.types import Vertex, UndirectedGraph, SizeIndex, EdgeLen, u64


class Instance(UndirectedGraph):
    """The BrazilianSalesman problem class."""

    start: Vertex
    edge_weights: Annotated[list[u64], EdgeLen]

    @property
    def size(self) -> int:
        return self.num_vertices


class Solution(SolutionModel[Instance]):
    """A solution to the Brazilian Salesman problem."""

    path: list[Vertex]

    def validate_solution(self, instance: Instance, role: Role) -> None:
        print(instance.edges)
        print(self.path)
        if self.path[0] != instance.start or self.path[-1] != instance.start:
            raise ValidationError("The path must start and end with the starting vertex.")
        visitedVertices = set()
        for i in range(len(self.path) - 1):
            visitedVertices.add(self.path[i])
            if not (self.path[i], self.path[i + 1]) in instance.edges and not (self.path[i+1], self.path[i])  in instance.edges:
                raise ValidationError("The given path doesnt exists in the instance.")       
        if len(visitedVertices) <  instance.size:
            raise ValidationError("The path does not visit every vertex at least once.")
               

    @minimize
    def score(self, instance: Instance, role: Role) -> float:
        speed = 0.9 if role == Role.solver else 1  # the solving team is faster than the generating
        print(speed)

        takenEdges = []
        length = 0
        #adding weights for the other direction of the path!
        for i in range(len(self.path) - 1):
            edgeweight = 0
            if (self.path[i], self.path[i+1]) in instance.edges:
                edgeweight = instance.edge_weights[instance.edges.index((self.path[i], self.path[i+1]))]
            else:
                edgeweight = instance.edge_weights[instance.edges.index((self.path[i+1], self.path[i]))]
            if (self.path[i], self.path[i+1]) in takenEdges or (self.path[i+1], self.path[i]) in takenEdges:
                length = length + 0.3*edgeweight
            else:
                length = length + edgeweight
                takenEdges.append( (self.path[i], self.path[i+1]) ) 
        print(length)

        length = length*speed
        print(length)

        return length

BrazilianSalesman = Problem(
    name="Brazilian Salesman",
    min_size=4,
    instance_cls=Instance,
    solution_cls=Solution,
)
#some more testing multiple edges