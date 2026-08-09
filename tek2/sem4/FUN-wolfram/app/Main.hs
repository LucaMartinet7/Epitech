{-
--
-- EPITECH PROJECT, 2024
-- B-FUN-400-BAR-4-1-wolfram-luca.martinet
-- File description:
-- Main
--
-}

module Main (main) where

import Wolf (getArgsStr)
import Algo (algo)
import System.Environment (getArgs)
import System.Exit (exitWith, ExitCode(ExitFailure))
import System.IO (hPutStrLn, stderr)

exitError :: String -> IO ()
exitError msg =
    hPutStrLn stderr ("Error: " ++ msg) >>
    exitWith (ExitFailure 84)

main :: IO ()
main = do
    args <- getArgs
    case getArgsStr args of
      Nothing -> exitError "Invalid arguments"
      Just ar -> algo ar
