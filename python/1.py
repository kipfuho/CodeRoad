DEEP_MAX = 3

def TRY(board, size, node, deep):
    if node.isX:
        board[node.x][node.y] = "X"
        # nếu không phải lá, gọi tiếp đến các con
        if deep < DEEP_MAX:
            for child in node.child:
                TRY(board, size, child, deep + 1)
        else:
            # đánh giá nước đi, lưu lại
            node.ep = 9999
        board[node.x][node.y] = 0
    else:
        board[node.x][node.y] = "O"
        # nếu không phải lá, gọi tiếp đến các con
        if deep < DEEP_MAX:
            for child in node.child:
                TRY(board, size, child, deep + 1)
        else:
            # đánh giá nước đi, lưu lại
            node.ep = -9999
        board[node.x][node.y] = 0
