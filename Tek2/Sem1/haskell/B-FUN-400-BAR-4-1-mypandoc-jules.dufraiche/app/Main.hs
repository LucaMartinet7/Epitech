{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BAR-4-1-mypandoc-jules.dufraiche
-- File description:
-- Main
-}

module Main (main) where

import System.Exit (exitWith, ExitCode(ExitFailure))
import System.IO (hPutStrLn, stderr)
import System.Environment (getArgs)
import HandleArgs (parseArgs)
import Process (process)

main :: IO ()
main =
  getArgs >>= \cliArgs ->
    maybe (hPutStrLn stderr "Error: Bad parameters" >>
      exitWith (ExitFailure 84))
          (\params -> process params)
          (parseArgs cliArgs)
