class Solution {
    fun solution(numbers: IntArray, hand: String): String {
        fun abs(a:Int): Int { return if(a > 0) a else -a }

        var lposx = 1
        var lposy = 3
        var rposx = 3
        var rposy = 3

        var answer = ""

        for (it in numbers) {
            val tmp = if (it==0) 11 else it
            if(tmp % 3 == 1) {
                lposx = 1
                lposy = tmp / 3
                answer += 'L'
            }
            else if (tmp % 3 == 2) {
                var ld = abs(lposx - 2) + abs(lposy - tmp/3)
                var rd = abs(rposx - 2) + abs(rposy - tmp/3)

                if (ld == rd) {
                    if (hand == "right") ld++
                    else if (hand == "left") rd++
                }

                if (ld > rd) {
                    rposx = 2
                    rposy = tmp/3
                    answer += 'R'
                }
                else {
                    lposx = 2
                    lposy = tmp/3
                    answer += 'L'
                }
            }
            else {
                rposx = 3
                rposy = tmp / 3 - 1
                answer += 'R'
            }
        }

        return answer
    }
}