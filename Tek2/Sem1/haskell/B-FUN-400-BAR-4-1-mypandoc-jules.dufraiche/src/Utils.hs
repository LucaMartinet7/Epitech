{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BAR-4-1-mypandoc-jules.dufraiche
-- File description:
-- utils
-}

module Utils (findOccurrence) where

import Data.List (isPrefixOf)

findOccurrence :: String -> String -> Int -> Maybe Int
findOccurrence _ [] _ = Nothing
findOccurrence _ _ i | i < 0 = Nothing
findOccurrence sub str i
    | i >= length str = Nothing
    | sub `isPrefixOf` drop i str = Just i
    | otherwise = findOccurrence sub str (i + 1)
