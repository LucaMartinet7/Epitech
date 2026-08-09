{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BAR-4-1-mypandoc-jules.dufraiche
-- File description:
-- FromJSON
-}

module FromJSON (fromJSON) where

import System.Exit (exitWith, ExitCode(ExitFailure))
import Data.List (elemIndex)
import Utils (findOccurrence)

fromJSON :: String -> Maybe String -> IO ()
fromJSON content (Just "json") = putStrLn content
fromJSON content (Just "xml") = toXML content
fromJSON content (Just "markdown") = toMarkdown content
fromJSON _ _ = putStrLn "Invalid format" >> exitWith (ExitFailure 84)

toXML :: String -> IO ()
toXML content =
    let headerIndex = findHeaderIndex content
    in case headerIndex of
        Just idx ->
            putStrLn "<document>" >>
            putKeyVal "xml" "title" (findHKeyVal "\"title\"" idx content) >>
            putKeyVal "xml" "author" (findHKeyVal "\"author\"" idx content) >>
            putKeyVal "xml" "date" (findHKeyVal "\"date\"" idx content) >>
            putStrLn "</header>"
        Nothing -> exitWith (ExitFailure 84)

toMarkdown :: String -> IO ()
toMarkdown content =
    let headerIndex = findHeaderIndex content
    in case headerIndex of
        Just idx ->
            putStrLn "---" >>
            putKeyVal "md" "title" (findHKeyVal "\"title\"" idx content) >>
            putKeyVal "md" "author" (findHKeyVal "\"author\"" idx content) >>
            putKeyVal "md" "date" (findHKeyVal "\"date\"" idx content) >>
            putStrLn "---\n"
        Nothing -> exitWith (ExitFailure 84)

putKeyVal :: String -> String -> Maybe String -> IO ()
putKeyVal "md" key (Just value) = putStrLn $ key ++ ": " ++ value
putKeyVal "xml" "title" (Just value) = putStrLn $ "<header title=\"" ++
            value ++ "\">"
putKeyVal "xml" key (Just value) = putStrLn $ "<" ++ key ++ ">" ++
            value ++ "</" ++ key ++ ">"
putKeyVal _ _ Nothing = return ()

findHeaderIndex :: String -> Maybe Int
findHeaderIndex content = findOccurrence "\"header\": {" content 0

findBodyIndex :: String -> Maybe Int
findBodyIndex content = findOccurrence "\"body\":" content 0

findHKeyVal :: String -> Int -> String -> Maybe String
findHKeyVal key i content = case findOccurrence key content i of
    Just idx -> Just $ takeWhile (/= '\"') $
        drop (idx + length key + 3) content
    Nothing -> Nothing
