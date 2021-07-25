680 ：名無しさん：2016/02/16(火) 09:44:42 ID:VRgYTkQw0
〔環境〕Emuera1820+v2
【バリアント】0.309＋修正6
【導入パッチ】eraMegaten0.309 + 修正パッチ6 + eraMegaten0.309用私家版パッチ纏め_Rev70+Rev72+(>>674)


調教関連\労役\SYSTEM_MANAGEMENT.ERBの243行目でエラーが発生しました:Emuera1820+v2
RETURNF DE:LOCAL:ARG
エラー内容：二次元配列DEの第２引数(-8)は配列の範囲外です
現在の関数：@店舗（調教関連\労役\SYSTEM_MANAGEMENT.ERBの236行目）
関数呼び出しスタック：
↑調教関連\EVENT_P.ERBの613行目（関数@CHANGE_N_STATUS内）
↑調教関連\EVENT_P.ERBの411行目（関数@GET_CHILD_MESSAGE内）
↑調教関連\EVENT_P.ERBの356行目（関数@GET_CHILD内）
↑調教関連\EVENT_S.ERBの162行目（関数@EVENT_NEWDAY内）
↑SYSTEM.ERBの751行目（関数@EVENTTURNEND内）
※※※ログファイルをemuera.logに出力しました※※※

初日に妊娠したらエラー 

688 ：名無しさん：2016/02/16(火) 15:40:03 ID:oZoFsIkI0
>>680
ttp://ux.getuploader.com/eraMegaten/download/3642/eraMegaten_3643.zip
これでどうでしょう 

689 ：名無しさん：2016/02/16(火) 16:00:53 ID:VRgYTkQw0
>>688
あ、治りました！問題なく次の日に移行できたみたいです
孕ませた相手（ガキ）に問題があるのかと勘繰ってましたが…いやはや、全く別の所だとは
ありがとうございました 