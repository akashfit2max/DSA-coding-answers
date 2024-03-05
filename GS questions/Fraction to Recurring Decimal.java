class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        // we have to apply long division tech
        if (numerator == 0) return "0";
        StringBuffer res = new StringBuffer();

        // + or -
        res.append(((numerator > 0) ^ (denominator > 0)) ? "-" : "");
        long num = Math.abs((long)numerator);
        long den = Math.abs((long)denominator);

        // integral part
        res.append(num / den);
        num %= den;

        if (num == 0) {
            return res.toString();
        }

        res.append(".");
        Map<Long, Integer> map = new HashMap<>();
        map.put(num, res.length());

        while (num != 0) {
            num *= 10;
            res.append(num / den);
            num %= den;
            if (map.containsKey(num)) {
                int ind = map.get(num);
                res.insert(ind, "(");
                res.append(")");
                break;
            } else {
                map.put(num, res.length());
            }
        }
        return res.toString();
    }
}