def matrix_reverse():
    row, col, method = (int(x) for x in input().strip().split(' '))
    matrix = [[0 for x in range(col)] for y in range(row)]
    for x in range(0, row):
        row_input = input().strip().split(' ')
        row_data = []
        for a in row_input:
            row_data.append(int(a))
        matrix[x] = row_data
    if int(method) == 1:
        for x in range(0, row):
            for y in range(0, col):
                print(matrix[-(x + 1)][y], end=' ')
            print('\r')
    elif int(method) == 0:
        for x in range(0, row):
            for y in range(0, col):
                print(matrix[x][-(y + 1)], end=' ')
            if x != row - 1:
                print('\r')


if __name__ == '__main__':
    matrix_reverse()
