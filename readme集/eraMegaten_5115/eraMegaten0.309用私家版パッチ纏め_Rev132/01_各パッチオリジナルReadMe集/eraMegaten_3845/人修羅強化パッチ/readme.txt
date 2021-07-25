人修羅強化パッチ

追加スキル
SKILL2098_至高の魔弾・人修羅
勾玉カイラースでlv70習得


SYSTEM_BATTLE_DAMAGE.ERB
人修羅ならダメージ上昇、戦闘時の素質影響設定 ON 1.3倍、OFF 1.1倍。

1065-1070行
;人修羅ならダメージ上昇、戦闘時の素質影響設定 ON 1.3倍、OFF 1.1倍。
IF TALENT:L_P:人修羅 && BATTLE_SETTING_IS_TALENT()
	TIMES L_DMG,1.3
ELSEIF TALENT:L_P:人修羅
	TIMES L_DMG,1.1
ENDIF


csv登録用

_RENAME.CSV
2098 , スキル:至高の魔弾・人修羅
12098 , アイテム:スキルカード【至高の魔弾・人修羅】

ITEM.CSV
12098,スキルカード【至高の魔弾・人修羅】,1
