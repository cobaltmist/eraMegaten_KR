# CONCERT小リファクタリングパッチ

## 概要

労役「コンサート」の機能拡張！　……を行いやすくするべく  
リファクタリング！　……の第一歩として  
ABLやTALENT等の指定を数値指定からCSV定義の名称指定へ変更するパッチです

具体的には ABL:A:14 のような指定を ABL:A:歌唱技能 に変更しています  
AとかBとかSとかの1文字変数も抹殺したかったのですが  
まず第一歩として数値指定の排除から……

あくまでリファクタリングのため機能としては全く変わっていませんが  
今後このパッチの作成者を含む誰かが労役「コンサート」の機能拡張を行う際に  
本パッチの導入により既存コードの把握および変更が行いやすくなると思います

## 対象環境

下記が順に導入された環境を対象としています

1. eraMegaten ver0.309: <https://ux.getuploader.com/eraMegaten_base/download/299>
2. 0.309用修正ファイル6: <https://ux.getuploader.com/eraMegaten_base/download/306>
3. 私家版パッチ纏め_Rev123: <https://ux.getuploader.com/eraMegaten/download/4476>
4. 私家版パッチ纏め_Rev124: <https://ux.getuploader.com/eraMegaten/download/4530>

## 導入方法

前述の対象環境への上書により導入可能です

## ライセンス

本パッチにおける変更は半機械的であり創造性はほぼ皆無な認識のため  
前述の対象環境における内容との変更差分についてのライセンスはCC0とします

<https://creativecommons.org/choose/zero/>

本パッチに含まれるファイル「CONCERT.ERB」の内容全体についてのライセンスは  
前述の対象環境のライセンスを参照ください
