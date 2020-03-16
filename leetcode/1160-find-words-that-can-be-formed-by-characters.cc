/*
 * @lc app=leetcode id=1160 lang=cpp
 *
 * [1160] Find Words That Can Be Formed by Characters
 *
 * https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/
 *
 * algorithms
 * Easy (66.82%)
 * Likes:    214
 * Dislikes: 48
 * Total Accepted:    34.7K
 * Total Submissions: 51.6K
 * Testcase Example:  '["cat","bt","hat","tree"]\n"atach"'
 *
 * You are given an array of strings words and a string chars.
 *
 * A string is good if it can be formed by characters from chars (each
 * character can only be used once).
 *
 * Return the sum of lengths of all good strings in words.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["cat","bt","hat","tree"], chars = "atach"
 * Output: 6
 * Explanation:
 * The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 =
 * 6.
 *
 *
 * Example 2:
 *
 *
 * Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
 * Output: 10
 * Explanation:
 * The strings that can be formed are "hello" and "world" so the answer is 5 +
 * 5 = 10.
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= words.length <= 1000
 * 1 <= words[i].length, chars.length <= 100
 * All strings contain lowercase English letters only.
 *
 */
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int countCharacters(vector<string> &words, string chars) {
        int res = 0;
        int charMap[26] = {0};
        vector<string> t;
        for (char c : chars) {
            charMap[c - 'a']++;
        }
        for (auto w : words) {
            int tmpMap[26];
            bool flag = true;
            memcpy(tmpMap, charMap, sizeof(charMap));
            for (char c : w) {
                if (tmpMap[c - 'a'] == 0) {
                    flag = false;
                    break;
                } else {
                    tmpMap[c - 'a']--;
                }
            }
            if (flag) {
                res += w.size();
            }
        }
        return res;
    }
};
// @lc code=end

int main() {

    vector<string> vec = {
        "pxlqovnbsgvqjzpfeidchzrodnbqfrccfydzjptukscjuatlsrcurepllxzyghhdepitqptlmfkhzxjgswaulxkfydhkilg",
        "uqklvqnlhdkwryjawkqfajfpbcnhglxlwxlaskxlytr",
        "jvgkxcdkxrvfahjkvhmfuyjzxtyxrsogbtsjybeaxugqymcr",
        "rgxditmosplnqvodtis",
        "jm",
        "ruqjwejuanjtiizcmbieobesnjnadzqvqumggblzmkxilgfarnxwpcawtkzxlvugibpidvwtikloeziuxqoi",
        "wxeyzrnbhlhwxecrgejsrawyulynvgtszwqqlihkcvckgcgtgpyqtkuwvjywmhpskaiwmpyarftqhnogxpith",
        "vdpbykqlihtpvfnqbrcjpggojqbalerohyitktuikbffvfatcnneuvbanjihiaorrjcdthntnrxebfhvshmpodmzhtwnasbm",
        "wgjstkoaojcesfdrllugmojwdmgeejyiqvshlowtktddattunarnohgvqsoskfmbrami",
        "ecwqxbawirvnxvsjybbebclaturorlcbpf",
        "gtjbaigvufrotlwfoqqolnjabnvtbcygtfcytinzpcjbvprdkdjawrcbthmxjrabimhhs",
        "cvzlbrvppkyxtjxzeglzwoagmpjnfxddbwolxmwdohgtfktgftzzkwpianslkpldyfzubtjczse",
        "neaw",
        "mxhmvkajofnmdiiduactlemcvpztscmsnrdhuhquxnnzywsrzxyplgbppiypxwcfbsnyzblaeifo",
        "krekecabfpufucjhqphjnibaeqdvdpmrfougdwugvoioqangdnxromwlxnfeydaneyazzclscqgdxlhhgnoqmslfflzqv",
        "klutvchxsceihfmzitgqakytesfjykribjhjzdruuoycjkwaghmmqkfrhkrtawudtjyjwqbyspamlegqjlwlj",
        "raykfkflqdzrpthdejetwolgciygwaktulkxemkdbbllkjxhnnafsms",
        "os",
        "xhchkcetmlprcdmrnalvkvgabxxnomphqpqhnddqhecogspbdebeoshvjgzvmqu",
        "jqtdysnpskktynxwmsfaabglagnqcllptvuyyqjwrmqaftenusmsahhhqubkwxltpr",
        "sulmwluiwvlroldpiyecaicwrawzwflokefqkdwmxejaovvpbflfdtviinbvvtlhhhefmgfsqs",
        "sxyhcckvyl",
        "vsaacsybcddxvuzkddjmuivsvtjyanpbydmkcwnkmxvsiantgkvkmqjysclsvd",
        "sxcghypulvmfqfunxj",
        "pozekufhlooosxpcggbi",
        "xzaoxzllcixfqbupqozmzrnugj",
        "j",
        "tgslwp",
        "ntrdkixexajlpjgmcbrqimwtqnzfrqjszeiuvrgzclerzmsnagzaxbredvlrmipzflrzusclckmxphc",
        "ifdflsywdfizpodsehrrifsvejcxarrxmxyjgbbvqyqvywncphzfmnxhybxpdcozfnzablfx",
        "uluhplzrsaehaqxfnbcmixueedevhirbwqdyztwaxnkogcauymxgcpabxekib",
        "agtfkinbdccoemxetbryzpluzlpyzicnfopphrxriqm",
        "pdympxpwvxwcqaxrvbvyqkrresrjgzgxuyfxtkgldtathokdbyfsqfmitmiyagtqgijaiazvsumeyutbbwxqdshquzrehn",
        "rqe",
        "sljsvenhhstnnngzqyo",
        "dezrzpgldeimxfoqajuhjctgvalwkhkjemjaxumxqmifglbizusuqlttxirpbqbuvauwy",
        "dkwpyezbmkcskoxxcgrxcewknqgdckjxfyzcmzqcbyeucxbqybxoldogtkmdknsrruvnlfqnpfx",
        "sjeftmjkuperfynbreycwhuoyqybticswblbrrpugzhlrmiedjqufnehevzqwtaebwvdswsz",
        "lolnfyliloqmhjmhhohdtgfajjfdjqpubslbsrwitbjmrcegdrdjzvonxaefdvdfcbqmaaks",
        "qhcoaiocjhuzywkirlblajgeapzajqsoa",
        "sxrmoqxqbtakuqwmrrkljmegbwbeqbywmlyuprwyhljzejbybxoumidpxdrohwdjoqycpxcmivaulnqzneydwqfsvcxgyyseuk",
        "yrowy",
        "dohrzkrzdjehpctnjrvhzojullsiucrhphshwxwicyzkvzbqrztic",
        "rmshnxtbhsdgkiijrmwulocdzjzpgfyimkjdthuzkhoqgkeawgwincubrloknocxwzgqqcxafksxgzh",
        "aymovnuhptozhkiyowbeguzlkmrwjnujgjbdne",
        "abc",
        "vxoigovwmqizmkwbkktqk",
        "uokwktdempzloaglvvkqstztmwzcmhgxtoua",
        "bzwjxqueazlzfojrkbqmhtwrvuwsnfcnylurnddpektekca",
        "qgndjgvzcyajhgmrrnhdywwdbmkhtthwcfiueuxfldanyrmccwcy"};
    Solution s;
    int r = s.countCharacters(vec, "figspbov");
    return 0;
}
