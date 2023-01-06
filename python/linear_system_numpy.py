#intersection of 2 lines: a1.x + b1.y = c1
#                         a2.x + b2.y = c2
#intersection of 3 planes: a1.x + b1.y + c1.z = d1
#                          a2.x + b2.y + c2.z = d2
#                          a3.x + b3.y + c3.z = d3

import numpy as np

def get_intersect_2d(A,B,C): # A=[a1,a2] B=[b1,b2] C=[c1,c2]

    det = np.linalg.det(np.array([A,B]))

    if det == 0:
        return (float('inf'), float('inf'))

    x = np.linalg.det(np.array([C,B])) / det
    y = np.linalg.det(np.array([A,C])) / det
    return (x, y)

def get_intersect_3d(A,B,C,D): # A=[a1,a2,a3] B=[b1,b2,b3] C=[c1,c2,c3] D=[d1,d2,d3]

    det = round(np.linalg.det(np.array([A,B,C])), 2)

    if det == 0:
        return (float('inf'), float('inf'))

    x = round(np.linalg.det(np.array([D,B,C])) / det, 2)
    y = round(np.linalg.det(np.array([A,D,C])) / det, 2)
    z = round(np.linalg.det(np.array([A,B,D])) / det, 2)
    return (x, y, z)

print(get_intersect_2d([1,2],[-1,3],[-2,6])) #problem 1
print(get_intersect_3d([1,2,1],[-1,-1,1],[0,-1,1],[2,3,6])) #problem 2
print(get_intersect_3d([1,4,9],[1,2,3],[1,1,1],[4,3,4])) #problem 3
print(get_intersect_3d([1,1,-2],[0,1,2],[1,-2,1],[1,-3,0])) #problem 4