

私家版Rev121用『人間と半魔も装備知識の恩恵を受けられるパッチ』
付属のＥＲＢフォルダを突っ込めば動く筈。



『弄った所メモ』

・SYSTEM_BATTLE.ERB　４５３～４６４行目辺り
人間がスキル『装備知識』を覚えている場合の処理を追加

・SKILL_EQUIPTHEROY.ERB
@SKILL_EQUIPTHEORY_EQUIP_STATUS　及び　@SKILL_EQUIPTHEORY_EQUIP_HIT　に人間か半魔の場合の処理を追加。
