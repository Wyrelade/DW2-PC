#ifndef STAG2000_8CE0_FUNCS_H
#define STAG2000_8CE0_FUNCS_H

/* Functions src/stag2000/stag2000_8CE0.c defines or declares, for the units after it
 * (in the single file the definition was the prototype for later code). */
void Stg20_LoadShopSellList(Actor *a);
void Stg20_ShopListUpdate(Actor *a);
void Stg20_FilterPartsList(Actor *a, s32 mode);
void Stg20_BuildUpgradeList(Actor *a);
void Stg20_WarpPadUpdate(Actor *a);
void Stg20_BeetleShopMenuDestroy(Actor *a);
void Stg20_BeetleShopMenuDraw(Actor *a);
s32 Stg20_ByteListHas(u8 *s, s32 c);
s32 Stg20_IsPartInstalled(s32 id);
s32 Stg20_GetPartFitMsg(s32 id);
s32 Stg20_CountOwnedItem(s32 id);
void Stg20_FormatPrice(u8 *out, s32 v);
void Stg20_LoadShopBuyList(Actor *a, s32 id);
void Stg20_ShopListRefresh(Actor *a);
void Stg20_ShopListDestroy(Actor *a);
void Stg20_ShopListDraw(Actor *a);
void Stg20_OpenMsgOrDesc(void *t, s32 id, Halves pos, s32 arg);
void Stg20_PartsListToBag(Actor *a);
void Stg20_GatherPartsList(Actor *a);
s32 Stg20_PartsListHas(Actor *a, s32 v);
void Stg20_PartsListRemove(Actor *a, s32 v);
void Stg20_InsertDescS16(s16 *list, s32 n, s32 v);
void Stg20_PartsListRefresh(Actor *a);
void Stg20_BeetlePartsDestroy(Actor *a);
void Stg20_BeetlePartsDraw(Actor *a);
s32 Stg20_CanUpgradePart(s32 item);
void Stg20_UpgradeListRefresh(Actor *a);
void Stg20_PartsUpgradeUpdate(Actor *task);
void Stg20_PartsUpgradeDestroy(Actor *a);
void Stg20_PartsUpgradeDraw(Actor *a);
Stg20FileRec *Stg20_GetMapDest(s32 i);
void Stg20_WarpPadInit(Actor *a, s32 v);
void Stg20_CameraUpdate(Actor *a);
void Stg20_CameraDraw(Actor *a);

#endif /* STAG2000_8CE0_FUNCS_H */
