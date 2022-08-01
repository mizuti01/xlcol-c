# xlcol-c

Excelのカラム表記をExcel形式⇔数字形式で相互変換する簡単なプログラム。

## カラムの表記形式

### 数字形式

最左を1とした数値表記。

### Excel形式

最左をAとしたアルファベット表記。
Z(26列目)の次はAA(27列目)となる。

## 使い方

```
xlcol <数字形式の整数>|<Excel形式のアルファベット文字列>
```

数値が与えられた場合は、数字形式とみなしExcel形式に変換する。
アルファベット文字列が与えられた場合は、Excel形式と見なし数字形式に変換する。

## ビルド

CMakeとコンパイラ(gcc等)が必要。

### WindowsでVisual Studioを使用する場合

ここではVisual Studio 2022 Communityを想定。
CMakeはVisual Studio付属のものを使用するので、C++デスクトップ開発のインストール必須。

```
"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
cmake -S . -B build -G "Visual Studio 17 2022"
cmake --build build --config Release
```
で、build/dist/Releaseの下に`xlcol`コマンドが生成される。

### その他の場合

* WindowsでMSYSを使用する場合
* Linuxの場合

macOSは未検証。

```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```
で、build/distの下に`xlcol`コマンドが生成される。
<!-- build/distに生成される共有ライブラリもセットのため、コピー時はセットでコピーすること。 -->

## その他

### 受理する列の文字列

* 数字形式: 1〜18278 (先頭に0を入れると正しく変換できないので注意!)
* Excel型式: A〜ZZZ (1文字〜3文字)

Excelで扱える列数を超過しているが、気にしない。
