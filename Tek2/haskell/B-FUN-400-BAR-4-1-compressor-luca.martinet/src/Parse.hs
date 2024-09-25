{-
--
-- EPITECH PROJECT, 2024
-- B-FUN-400-BAR-4-1-compressor-luca.martinet
-- File description:
-- Parse
--
-}

module Parse (getOpt, Args(argsColors, argsConvergence, argsFile))where

import Text.Read (readMaybe)

data Args =
  Args { argsColors :: Int, argsConvergence :: Float, argsFile :: String }

defaultArgs :: Args
defaultArgs = Args { argsColors = 0, argsConvergence = -1, argsFile = "" }

setColors :: Args -> Int -> Maybe Args
setColors args val
    | val <= 0 = Nothing
    | otherwise = Just (args { argsColors = val })

setConvergence :: Args -> Float -> Maybe Args
setConvergence args val
    | val < 0 = Nothing
    | otherwise = Just (args { argsConvergence = val })

setFile :: Args -> String -> Maybe Args
setFile args val = Just (args { argsFile = val })

assignArgVal :: String -> String -> Args -> Maybe Args
assignArgVal "-n" val args = readMaybe val >>= setColors args
assignArgVal "-l" val args = readMaybe val >>= setConvergence args
assignArgVal "-f" val args = setFile args val
assignArgVal _ _ _ = Nothing

parse :: [String] -> Maybe Args -> Maybe Args
parse [] args = args
parse [_] _ = Nothing
parse (opt:val:rest) (Just args) = parse rest (assignArgVal opt val args)
parse _ _ = Nothing

isError :: [String] -> Bool
isError args
    | "-n" `notElem` args = True
    | "-l" `notElem` args = True
    | "-f" `notElem` args = True
    | otherwise = False

getOpt :: [String] -> Maybe Args
getOpt args
    | isError args = Nothing
    | otherwise = parse args (Just defaultArgs)