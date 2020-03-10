package leetcode

var h, w int

func search(x, y, d int, board [][]byte, word string) bool {
	if x == w || x < 0 || y == h || y < 0 {
		return false
	}
	if board[y][x] != word[d] {
		return false
	}
	if d == len(word)-1 {
		return true
	}
	curr := board[x][y]
	board[y][x] = 0
	found := search(x+1, y, d+1, board, word) || search(x-1, y, d+1, board, word) ||
		search(x, y+1, d+1, board, word) || search(x, y-1, d+1, board, word)
	board[y][x] = curr
	return found
}

func exist(board [][]byte, word string) bool {
	h = len(board)
	if h == 0 {
		return false
	}
	w = len(board[0])
	for i := 0; i < w; i++ {
		for j := 0; j < h; j++ {
			if search(i, j, 0, board, word) {
				return true
			}
		}
	}
	return false
}
