import java.util.HashMap;

public class Main {
    public static boolean isIsomorphic(String s, String t) {
        boolean ans = true;
        HashMap<String, String> map = new HashMap<String, String>();
        for (int i = 0; i < s.length(); i++) {
            String c1 = Character.toString(s.charAt(i));
            String c2 = Character.toString(t.charAt(i));
            if (map.containsKey(c1)) {
                ans = ans && map.get(c1).equals(c2);
            } else if (map.containsValue(c2)) {
                return false;
            } else {
                map.put(c1, c2);
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        String s = "paper", t = "title";
        System.out.println(isIsomorphic(s, t));
    }
}