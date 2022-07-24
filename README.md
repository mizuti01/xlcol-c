# xlcol-c

Excelのカラム表記をExcel形式⇔Lotus形式で相互変換する簡単なプログラム。

## カラムの表記形式

### Lotus形式

最左を1とした数値表記。

### Excel形式

最左をAとしたアルファベット表記。
Z(26列目)の次はAA(27列目)となる。

## 使い方

```
xlcol <Lotus形式の整数>|<Excel形式のアルファベット文字列>
```

数値が与えられた場合は、Lotus形式とみなしExcel形式に変換する。
アルファベット文字列が与えられた場合は、Excel形式と見なしLotus形式に変換する。

## ビルド

CMakeとコンパイラ(gcc等)が必要。

```
cmake -S . -B build
cmake --build build
```
で、build/distの下に`xlcol`コマンドが生成される。
build/distに生成される共有ライブラリもセットのため、コピー時はセットでコピーすること。

## その他

### 受理する列の文字列

* Lotus形式: 1〜18278
* Excel型式: A〜ZZZ (1文字〜3文字)

Excelで扱える列数を超過しているが、気にしない。
