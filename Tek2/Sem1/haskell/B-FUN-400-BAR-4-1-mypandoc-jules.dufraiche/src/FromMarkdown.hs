{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BAR-4-1-mypandoc-jules.dufraiche
-- File description:
-- FromMarkdown
-}

module FromMarkdown (fromMarkdown) where

import System.Exit (exitWith, ExitCode(ExitFailure))

fromMarkdown :: String -> Maybe String -> IO ()
fromMarkdown content (Just "markdown") = putStrLn content
fromMarkdown content (Just "xml") = putStrLn "markdown to xml"
fromMarkdown content (Just "json") = putStrLn "markdown to json"
fromMarkdown _ _ = putStrLn "Invalid format" >> exitWith (ExitFailure 84)

-- toXML :: String -> IO ()

-- toJSON :: String -> IO ()
