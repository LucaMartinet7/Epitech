{-
--
-- EPITECH PROJECT, 2024
-- B-PDG-300-BAR-3-1-PDGD03-luca.martinet
-- File description:
-- Tree
--
-}

data Tree a = Empty
        | Node (Tree a) a (Tree a)
    deriving (Show)
