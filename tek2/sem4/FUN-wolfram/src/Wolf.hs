{-
--
-- EPITECH PROJECT, 2024
-- B-FUN-400-BAR-4-1-wolfram-luca.martinet
-- File description:
-- Wolf
--
-}

module Wolf (parseArg, getArgsStr, Ar(arRule, arStart, arHeight, arWidth, arMove)) where

import Text.Read (readMaybe)

data Ar = Ar { arRule :: Int, arStart :: Int, arHeight :: Maybe Int, arWidth :: Int, arMove :: Int } deriving (Show)

defaultVal :: Ar
defaultVal = Ar
    { arRule = 0, arStart = 0, arHeight = Nothing, arWidth = 80, arMove = 0 }

setRule :: Ar -> Int -> Maybe Ar
setRule ar val
    | val >= 0 && val <= 255 = Just (ar { arRule = val })
    | otherwise = Nothing

setStart :: Ar -> Int -> Maybe Ar
setStart ar val
    | val >= 0 = Just (ar { arStart = val })
    | otherwise = Nothing

setWidth :: Ar -> Int -> Maybe Ar
setWidth ar val
    | val >= 0 = Just (ar { arWidth = val })
    | otherwise = Nothing

setHeight :: Ar -> Int -> Maybe Ar
setHeight ar val
    | val >= 0 = Just (ar { arHeight = Just val })
    | otherwise = Nothing

setMove :: Ar -> Int -> Maybe Ar
setMove ar val = Just (ar { arMove = val })

isError :: [String] -> Bool
isError args
  | "--rule" `notElem` args = True
  | otherwise = False

getArgsStr :: [String] -> Maybe Ar
getArgsStr args
  | isError args = Nothing
  | otherwise = parse args (Just defaultVal)

parse :: [String] -> Maybe Ar -> Maybe Ar
parse [] (Just ar) = Just ar
parse (opt:val:rest) (Just ar) = do
    newAr <- parseArg opt (readMaybe val) ar
    parse rest (Just newAr)
parse _ _ = Nothing

parseArg :: String -> Maybe Int -> Ar -> Maybe Ar
parseArg "--rule" (Just val) ar = setRule ar val
parseArg "--start" (Just val) ar = setStart ar val
parseArg "--lines" (Just val) ar = setHeight ar val
parseArg "--window" (Just val) ar = setWidth ar val
parseArg "--move" (Just val) ar = setMove ar val
parseArg _ _ _ = Nothing
