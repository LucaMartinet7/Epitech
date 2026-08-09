{-
--
-- EPITECH PROJECT, 2024
-- B-PDG-300-BAR-3-1-PDGD03-luca.martinet
-- File description:
-- Game
--
-}

data Item = Sword | Bow | MagicWand
    deriving Eq

instance Show Item where
    show Sword = "sword"
    show Bow = "bow"
    show MagicWand = "magic wand"

data Mob = Mummy | Skeleton (Item) | Witch (Maybe Item)
    deriving Eq

createMummy :: Mob
createMummy = Mummy

createArcher :: Mob
createArcher = Skeleton Bow

createKnight :: Mob
createKnight = Skeleton Sword

createWitch :: Mob
createWitch = Witch Nothing

createSorceress :: Mob
createSorceress = Witch (Just MagicWand)

create :: String -> Maybe Mob
create "mummy" = Just createMummy
create "doomed archer" = Just createArcher
create "dead knight" = Just createKnight
create "witch" = Just createWitch
create "sorceress" = Just createSorceress
create _ = Nothing

equip :: Item -> Mob -> Maybe Mob
equip _ Mummy = Nothing
equip i (Skeleton _) = Just (Skeleton i)
equip i (Witch _) = Just (Witch (Just i))

instance Show Mob where
    show Mummy = "mummy"
    show (Skeleton Bow) = "doomed archer"
    show (Skeleton Sword) = "dead knight"
    show (Skeleton i) = "skeleton holding a " ++ show i
    show (Witch Nothing) = "witch"
    show (Witch (Just MagicWand)) = "sorceress"
    show (Witch (Just i)) = "witch holding a " ++ show i

class HasItem a where
    getItem :: a -> Maybe Item
    hasItem :: a -> Bool
    hasItem item =
        case getItem item of
            Just _ -> True
            Nothing -> False

instance HasItem Mob where
    getItem Mummy = Nothing
    getItem (Skeleton item) = Just item
    getItem (Witch(Just item)) = Just item
    getItem _ = Nothing
