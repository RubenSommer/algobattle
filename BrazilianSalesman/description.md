# Brazilian Salesman 

This problem is a variant of the well known traveling salesman problem, basically a mix of the spanning tree and the tsp problem:

**Given**: An undirected, weighted graph with `size` many vertices.  
**Problem**: Find a tour visiting every location at least once such that the total time taken is minimal.

The solver is given an advantage for this problem. Its salesman only needs 0.9 times the time that the generator would need.

The generator outputs both an instance and a certificate solution. Solvers are scored based on how fast their
salesman can complete its tour. When visiting an edge for a first time, it takes the edge weights time to traverse it - for the second, third,... time, the edge only costs 0.3*edge_weight for traversing. Here the salesman can take advantage of the fact, that he already chopped a path in the jungle he can take.algobattle

## Instances

An instance contains of the number of vertices, the edges, the start/end vertex and the edgeweights

```json
{
    "num_vertices": 5,
            "edges": [
                [0, 1],
                [0, 2],
                [0, 3],
                [0, 4],
                [1, 2],
                [1, 3],
                [1, 4],
                [2, 3],
                [2, 4],
                [3, 4],
            ],
            "start": 0,
            "edge_weights": [1, 1, 1, 1, 1, 2, 2, 2, 2, 2],
}
```

## Solutions

Solutions just contain the path of vertices in the order they are visited.

```json
{
    "path": [0, 1, 0, 2, 3, 4, 0],
}
```
