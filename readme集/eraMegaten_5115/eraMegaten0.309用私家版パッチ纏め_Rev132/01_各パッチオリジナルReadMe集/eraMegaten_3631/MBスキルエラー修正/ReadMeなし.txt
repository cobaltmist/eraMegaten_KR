【女神転生】eraMegaten【メタトロンLV97】より引用

666 ：あなたの名前を入力してください：2016/01/05(火) 18:17:13 ID:n0F6OigM
0.309+patch6+私家版パッチ纏めrev70+71：

リーズが正式外典を習得するにはスキルが一杯だ。
破棄するスキルを選んでください
-------------------------------------------------------------------------------------------------------------------------------------
【剣撃】 正式外典
種別：攻撃　相性：打撃
組み込み関数\キャラクタデータ参照／BASE\現HP割合.ERBの6行目でエラーが発生しました:Emuera1820+v2
RETURNF BASE:ARG:ＨＰ * 100 / MAXBASE:ARG:ＨＰ
エラー内容：キャラクタ配列変数MAXBASEの第１引数(-1)はキャラ登録番号の範囲外です
現在の関数：@現HP割合（組み込み関数\キャラクタデータ参照／BASE\現HP割合.ERBの4行目）
関数呼び出しスタック：
↑RPG\スキル関係\型月\SKILL2980_正式外典.ERBの14行目（関数@SKILL_POWER_2980内）
↑RPG\スキル関係\SYSTEM_SKIL.ERBの45行目（関数@SKILL_EXPLAIN_PERFORMANCE内）
↑RPG\戦闘\SYSTEM_LEVELUP.ERBの394行目（関数@LEARN_SKILL内）
↑RPG\戦闘\SYSTEM_LEVELUP.ERBの298行目（関数@EVENT_LEVELUP内）
↑RPG\戦闘\SYSTEM_LEVELUP.ERBの255行目（関数@CHECK_LEVEL_UP_NEW内）
↑RPG\戦闘\SYSTEM_LEVELUP.ERBの40行目（関数@CHECK_LEVEL_UP内）
↑RPG\戦闘\BATTLE.ERBの2166行目（関数@BATTLE_WIN内）
↑RPG\戦闘\BATTLE.ERBの1600行目（関数@BATTLE_END内）
↑RPG\戦闘\BATTLE.ERBの598行目（関数@BATTLE_MAIN内）
↑RPG\戦闘\BATTLE.ERBの50行目（関数@BATTLE_START内）
↑RPG\ダンジョンアタック\SYSTEM_DUNGEON.ERBの1116行目（関数@WALK_DUNGEON内）
↑RPG\ダンジョンアタック\SYSTEM_DUNGEON.ERBの636行目（関数@DUNGEON_ATTACK内）
↑RPG\ダンジョンアタック\SYSTEM_DUNGEON.ERBの115行目（関数@SHOP_COM_101内）
↑ＳＨＯＰ関連\SHOP.ERBの238行目（関数@USERSHOP内）


742 ：215：2016/01/06(水) 22:30:17 ID:3woiQvnQ
>>666
ご迷惑おかけしております。
修正パッチを上げてきました。
http://ux.getuploader.com/eraMegaten/download/3631/eraMegaten_3631.zip  