// Ex12-B: ComputeInitials
// コマンドライン引数で渡された名前のイニシャル（各単語の頭文字を大文字）を出力する。
// 例: java ComputeInitials "Momo Taro"  ->  My initials are: MT
class ComputeInitials {
    public static void main(String[] args) {
        String name = args[0];
        String[] words = name.split("\\s+");   // 空白で単語に分割
        StringBuilder initials = new StringBuilder();
        for (String word : words) {
            if (word.length() > 0) {
                initials.append(Character.toUpperCase(word.charAt(0)));
            }
        }
        System.out.println("My initials are: " + initials);
    }
}
