/*
 * @lc app=leetcode.cn id=297 lang=golang
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (55.65%)
 * Likes:    620
 * Dislikes: 0
 * Total Accepted:    98K
 * Total Submissions: 176K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 *
 * Clarification: The input/output format is the same as how LeetCode
 * serializes a binary tree. You do not necessarily need to follow this format,
 * so please be creative and come up with different approaches yourself.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,null,null,4,5]
 * Output: [1,2,3,null,null,4,5]
 *
 *
 * Example 2:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1]
 * Output: [1]
 *
 *
 * Example 4:
 *
 *
 * Input: root = [1,2]
 * Output: [1,2]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^4].
 * -1000 <= Node.val <= 1000
 *
 *
 */
package leetcode_297

import (
	"reflect"
	"testing"
)

func TestCodec_deserialize(t *testing.T) {
	type args struct {
		data string
	}
	tests := []struct {
		name string
		args args
		want *TreeNode
	}{
		{
			args: args{data: "[1]"},
			want: nil,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			this := &Codec{}
			if got := this.deserialize(tt.args.data); !reflect.DeepEqual(got, tt.want) {
				t.Errorf("Codec.deserialize() = %v, want %v", got, tt.want)
			}
		})
	}
}
