#or equations solver

from sympy import Matrix, solve_linear_system
from sympy.abc import x, y, z

def solve_3(A,B,C):
    system = Matrix((A,B,C))
    print(solve_linear_system(system, x, y, z))

def solve_2(A,B):
    system = Matrix((A,B))
    print(solve_linear_system(system, x, y))

solve_2((1,-1,-2),(2,3,6)) # problem 1
solve_3((1,-1,0,2),(2,-1,-1,3),(1,1,1,6)) # problem 2
solve_3((1,1,1,4),(4,2,1,3),(9,3,1,4)) # problem 3
solve_3((1,0,1,1),(1,1,-2,-3),(-2,2,1,0)) # problem 4