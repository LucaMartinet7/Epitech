{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BAR-4-1-mypandoc-jules.dufraiche
-- File description:
-- GetFormat
-}

module Process (process) where

import Data.List (isPrefixOf)

import System.IO (readFile, Handle, hGetContents, openFile, hClose, IOMode(ReadMode))
import System.Exit (exitWith, ExitCode(ExitFailure))

import Control.Exception (evaluate, bracket, catch)
import System.IO.Error (catchIOError)

import HandleArgs (Flags(iFlag, fFlag, oFLag, eFlag))
import FromXML (fromXML)
import FromMarkdown (fromMarkdown)
import FromJSON (fromJSON)

data FileType = XML | Markdown | JSON | Unknown deriving (Show)

toConverter :: String -> Maybe String -> Maybe FileType -> IO ()
toConverter content toFormat (Just XML) = fromXML content toFormat
toConverter content toFormat (Just Markdown) = fromMarkdown content toFormat
toConverter content toFormat (Just JSON) = fromJSON content toFormat
toConverter _ _ _ = putStrLn "bad file format" >> exitWith (ExitFailure 84)

getFileLanguage :: Maybe String -> Maybe FileType
getFileLanguage (Just path) =
    case reverse path of
        ('l':'m':'x':'.':_) -> Just XML
        ('d':'m':'.':_) -> Just Markdown
        ('n':'o':'s':'j':'.':_) -> Just JSON
        _ -> Nothing
getFileLanguage Nothing = Nothing

openTheFile :: String -> IO (Maybe String)
openTheFile path = do
    contents <- readFile path `catchIOError` (\_ -> return "")
    return (Just contents)

process :: Flags -> IO ()
process flags =
    case iFlag flags of
        Nothing -> putStrLn "Error: Missing input file" >>
                   exitWith (ExitFailure 84)
        Just path -> openTheFile path >>= \contents ->
            case contents of
                Nothing ->  putStrLn "Error: Error while opening the file" >>
                            exitWith (ExitFailure 84)
                Just content -> toConverter content (fFlag flags)
                                (getFileLanguage (iFlag flags))
