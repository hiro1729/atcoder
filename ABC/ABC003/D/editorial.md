# ABC003 D - AtCoder社の冬 解説

## 問題概要

$R \times C$ の区画内に $D$ 個のデスクと、 $L$ 個のサーバーラックがあり、それらすべてが含まれる最小の領域は $X \times Y$ になった。このとき、元のデスクとサーバーラックの配置は何パターンあるか、 $1000000007$ で割って求める。

## 制約

$$ 1 \leqq R,C \leqq 30 $$

$$ 1 \leqq X \leqq R $$

$$ 1 \leqq Y \leqq C $$

$$ 0 \leqq D,L $$

$$ 1 \leqq D+L \leqq X \times Y $$

## 考察

$X \times Y$ の区画の全探索は簡単。答えは $(R-X+1) \times (C-Y+1) \times (X \times Yのときの答え)$ になる。さらに簡単にしたいので、デスクとサーバーラックを合わせて考える。 $D+L$ 個から $D$ 個を選ぶので、答えは $(R-X+1) \times (C-Y+1) \times (X \times YからD+L個を選ぶ方法) \times {}_{D+L}C_D$ になる。

$X \times YからD+L個を選ぶ方法$ について。実際は条件がもっと増える。一番上、一番下の行、一番左、一番右の列のそれぞれのどこかにはデスクかサーバーラックがなければいけない。

<details><summary>包除原理</summary>

* 例: 2つのとき
2つの集合 $A$ と $B$ があったとき、

$$|A \cup B| = |A| + |B| - |A \cap B|$$

* 3つのとき

$$|A \cup B \cup C| = |A| + |B| + |C| - |A \cap B| - |B \cap C| - |C \cap A| + |A \cap B \cap C|$$

</details>

4つの集合に対する包除原理を使う。上下左右とは、一番その方向にある行または列にデスクかサーバーラックがあるかどうかである。

|上下左右|符号|式|
|----|----|--|
|oooo|+| $`{}_{X \times Y}C_{D+L}`$ |
|ooox|-| $`{}_{X \times (Y-1)}C_{D+L}`$ |
|ooxo|-| $`{}_{X \times (Y-1)}C_{D+L}`$ |
|oxoo|-| $`{}_{(X-1) \times Y}C_{D+L}`$ |
|xooo|-| $`{}_{(X-1) \times Y}C_{D+L}`$ |
|ooxx|+| $`{}_{X \times (Y-2)}C_{D+L}`$ |
|oxox|+| $`{}_{(X-1) \times (Y-1)}C_{D+L}`$ |
|oxxo|+| $`{}_{(X-1) \times (Y-1)}C_{D+L}`$ |
|xoox|+| $`{}_{(X-1) \times (Y-1)}C_{D+L}`$ |
|xoxo|+| $`{}_{(X-1) \times (Y-1)}C_{D+L}`$ |
|xxoo|+| $`{}_{(X-2) \times Y}C_{D+L}`$ |
|oxxx|-| $`{}_{(X-1) \times (Y-2)}C_{D+L}`$ |
|xoxx|-| $`{}_{(X-1) \times (Y-2)}C_{D+L}`$ |
|xxox|-| $`{}_{(X-2) \times (Y-1)}C_{D+L}`$ |
|xxxo|-| $`{}_{(X-2) \times (Y-1)}C_{D+L}`$ |
|xxxx|+| $`{}_{(X-2) \times (Y-2)}C_{D+L}`$ |

これらをまとめると答えは以下のようになる。ただし、 $a$ や $b$ が負のときは $`{}_a C_b`$ は $0$ とする。

$`({}_{X \times Y}C_{D+L} - {}_{X \times (Y-1)}C_{D+L} \times 2 - {}_{(X-1) \times Y}C_{D+L} \times 2 + {}_{X \times (Y-2)}C_{D+L} + {}_{(X-1) \times (Y-1)}C_{D+L} \times 4 + {}_{(X-2) \times Y}C_{D+L} - {}_{(X-1) \times (Y-2)}C_{D+L} \times 2 - {}_{(X-2) \times (Y-1)}C_{D+L} \times 2 + {}_{(X-2) \times (Y-2)}C_{D+L}) \times (R-X+1) \times (C-Y+1) \times {}_{D+L}C_D`$

## コード

``` cpp
// ライブラリ省略
const int mod=1000000007;
int main() {
  ll r, c, x, y, d, l;
  cin >> r >> c >> x >> y >> d >> l;
  mComb mc; mc.init(2000);
  auto c2 = [&](int a, int b) -> ll {
    if (a <= 0 || b <= 0 || a * b < l + d)
      return 0;
    return mc.C(a * b, d + l);
  };
  ll ans = 0;
  ans += c2(x, y);
  ans -= c2(x, y - 1) * 2 + c2(x - 1, y) * 2;
  ans += c2(x, y - 2) + c2(x - 1, y - 1) * 4 + c2(x - 2, y);
  ans -= c2(x - 1, y - 2) * 2 + c2(x - 2, y - 1) * 2;
  ans += c2(x - 2, y - 2);
  ans %= mod;
  ans *= (r - x + 1) * (c - y + 1) * mc.C(d + l, d) % mod;
  cout << (ans % mod + mod) % mod << '\n';
}
```