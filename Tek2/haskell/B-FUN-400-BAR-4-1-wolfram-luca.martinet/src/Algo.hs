{-
--
-- EPITECH PROJECT, 2024
-- B-FUN-400-BAR-4-1-wolfram-luca.martinet
-- File description:
-- Algo
--
-}

module Algo(algo) where

import Data.Bits (shiftR, Bits((.&.)))
import Wolf(Ar(arRule, arStart, arHeight, arWidth, arMove))

moved :: Int -> String -> String
moved move line
    | move >= 0 = replicate move ' ' ++ take (length line - move) line
    | otherwise = drop (abs move) line ++ replicate (abs move) ' '

getLeftSpace :: Int -> Int -> String
getLeftSpace lineLength width
  | lineLength >= width = ""
  | otherwise = replicate
    ((width - lineLength) `div` 2 + ((width - lineLength) `mod` 2))
    ' '

getRightSpace :: Int -> Int -> String
getRightSpace lineLength width
  | lineLength >= width = ""
  | otherwise = replicate ((width - lineLength) `div` 2) ' '

formatDisp :: String -> Int -> String
formatDisp line width =
    getLeftSpace lineLength width ++ line ++ getRightSpace lineLength width
    where
        lineLength = length line

display :: Int -> Int -> Int -> String -> IO ()
display start width move nextline
    | start > 0 = return ()
    | otherwise = putStrLn $ moved move (take width
        (drop ((length factored - width) `div` 2) factored))
    where
        factored = formatDisp nextline width

genChar :: Int -> Int -> String
genChar rule pattern
    | (rule `shiftR` pattern) .&. 1 == 1 = "*"
    | otherwise = " "

patternToInt :: String -> Int
patternToInt = foldl (\acc c -> acc * 2 + if c == '*' then 1 else 0) 0

getNextLine :: String -> Int -> String
getNextLine [] _ = ""
getNextLine [_] _ = ""
getNextLine [_, _] _ = ""
getNextLine prevline rule = genChar rule (patternToInt line) ++
        getNextLine (tail prevline) rule
    where line = take 3 prevline

loop :: Int -> String -> Ar -> IO ()
loop 0 _ _ = return ()
loop iteration nextline ar =
    display (arStart ar) (arWidth ar) (arMove ar) nextline >>
    loop (if (arStart ar) > 0 then iteration else iteration - 1)
         (getNextLine ("  " ++ nextline ++ "  ") (arRule ar))
         ar {arStart = arStart ar - 1}

checkHeight :: Maybe Int -> Int
checkHeight Nothing = -1
checkHeight (Just height) = height

algo :: Ar -> IO ()
algo ar = loop (checkHeight (arHeight ar)) "*" ar
