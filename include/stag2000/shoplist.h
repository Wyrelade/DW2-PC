#ifndef STAG2000_SHOPLIST_H
#define STAG2000_SHOPLIST_H

/* Functions src/stag2000/shoplist.c defines. */
void Stg20_LoadShopSellList(Actor *a);
void Stg20_ShopListUpdate(Actor *a);
s32 Stg20_ByteListHas(u8 *s, s32 c);
s32 Stg20_IsPartInstalled(s32 id);
s32 Stg20_GetPartFitMsg(s32 id);
s32 Stg20_CountOwnedItem(s32 id);
void Stg20_FormatPrice(u8 *out, s32 v);
void Stg20_LoadShopBuyList(Actor *a, s32 id);
void Stg20_ShopListRefresh(Actor *a);
void Stg20_ShopListDestroy(Actor *a);
void Stg20_ShopListDraw(Actor *a);

#endif /* STAG2000_SHOPLIST_H */
