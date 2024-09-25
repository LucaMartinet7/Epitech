{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BAR-4-1-mypandoc-jules.dufraiche
-- File description:
-- FromXML
-}

module FromXML (fromXML) where

import System.Exit (exitWith, ExitCode(ExitFailure))
import Utils (findOccurrence)

fromXML :: String -> Maybe String -> IO ()
fromXML content (Just "xml") = putStrLn content
fromXML content (Just "markdown") = toMarkdown content
fromXML content (Just "json") = toJSON content
fromXML _ _ = putStrLn "Invalid format" >> exitWith (ExitFailure 84)

toJSON :: String -> IO ()
toJSON content =
    let headerIndex = findHeaderIndex content
    in case headerIndex of
        Just idx ->
            putStrLn "{\n\"header\": {" >>
            putKeyVal "" "\"title\":" (findHKeyVal "title=\"" idx content) >>
            putKeyVal "" "\"author\":" (findHKeyVal "<author>" idx content) >>
            putKeyVal "" "\"date\":" (findHKeyVal "<date>" idx content) >>
            putStrLn "},"
        Nothing -> exitWith (ExitFailure 84)

toMarkdown :: String -> IO ()
toMarkdown content =
    let headerIndex = findHeaderIndex content
    in case headerIndex of
        Just idx ->
            putStrLn "---" >>
            putKeyVal "md" "title" (findHKeyVal "title=\"" idx content) >>
            putKeyVal "md" "author" (findHKeyVal "<author>" idx content) >>
            putKeyVal "md" "date" (findHKeyVal "<date>" idx content) >>
            putStrLn "---\n"
        Nothing -> exitWith (ExitFailure 84)

putKeyVal :: String -> String -> Maybe String -> IO ()
putKeyVal "md" key (Just value) = putStrLn $ key ++ ": " ++ value
putKeyVal "" key (Just value) = putStrLn $ key ++ " \"" ++ value ++ "\","
putKeyVal _ _ Nothing = return ()

findHeaderIndex :: String -> Maybe Int
findHeaderIndex content = findOccurrence "<header" content 0

findBodyIndex :: String -> Maybe Int
findBodyIndex content = findOccurrence "<body>" content 0

findHKeyVal :: String -> Int -> String -> Maybe String
findHKeyVal key i content = case findOccurrence key content i of
    Just idx -> Just $ takeWhile (\c -> c /= '<' && c /= '\"') $
        drop (idx + length key) content
    Nothing -> Nothing
