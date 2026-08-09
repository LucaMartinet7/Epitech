{-
--
-- EPITECH PROJECT, 2024
-- B-PDG-300-BAR-3-1-PDGD02-luca.martinet
-- File description:
-- DoOp
--
-}

import Data.List
import Data.Char
import Prelude

myElem :: Eq a => a -> [a] -> Bool
myElem a [] = False
myElem c (a:b) = if c == a then True else myElem c b

safeDiv :: Int -> Int -> Maybe Int
safeDiv c 0 = Nothing
safeDiv a b = Just (a `div` b)

safeNth :: [a] -> Int -> Maybe a
safeNth [] _ = Nothing
safeNth (a:b) c
    | c < 0 = Nothing
    | c > length(b) + 1 = Nothing
safeNth (a:b) 0 = Just a
safeNth (a:b) c = (safeNth b (c - 1))

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc (Just a) = Just (a + 1)

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup _ [] = Nothing
myLookup a ((b, c):d)
    | a == b = Just c
    | otherwise = myLookup a d

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo _ Nothing _ = Nothing
maybeDo _ _ Nothing = Nothing
maybeDo a (Just b) (Just c) = Just (a b c)

checkLetters :: String -> Bool
checkLetters str = all isDigit str

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt "-" = Nothing
readInt c
    | head c == '-' && all isDigit (tail c) = Just (read c)
    | all isDigit c = Just (read c)
    | otherwise = Nothing

getLineLength :: IO Int
getLineLength = do
        line <- getLine
        return (length line)

printAndGetLength :: String -> IO Int
printAndGetLength str = putStrLn str >> return (length str)

getInt :: IO (Maybe Int)
getInt = do
        str <- getLine
        return (readInt str)
