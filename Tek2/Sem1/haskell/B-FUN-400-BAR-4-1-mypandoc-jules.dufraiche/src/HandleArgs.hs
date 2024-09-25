{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BAR-4-1-mypandoc-jules.dufraiche
-- File description:
-- HandleArgs
-}

module HandleArgs (parseArgs, Flags(iFlag, fFlag, oFLag, eFlag)) where

import Data.Maybe (isJust)

data Flags = Flags {
                iFlag :: Maybe String,
                fFlag :: Maybe String,
                oFLag :: Maybe String,
                eFlag :: Maybe String
                }

defaultFlags :: Flags
defaultFlags = Flags {
                iFlag = Nothing,
                fFlag = Nothing,
                oFLag = Nothing,
                eFlag = Nothing
                }

validType :: Maybe String -> Bool
validType (Just "markdown") = True
validType (Just "xml") = True
validType (Just "json") = True
validType _ = False

parseArgs :: [String] -> Maybe Flags
parseArgs args
    | isJust i && validType f = Just flags
    | otherwise = Nothing
    where
        flags = parseFlags args defaultFlags
        i = iFlag flags
        f = fFlag flags

parseFlags :: [String] -> Flags -> Flags
parseFlags [] flags = flags
parseFlags ("-i":args) flags = parseFlags (tail args)
    (flags { iFlag = getFlagValue args })
parseFlags ("-f":args) flags = parseFlags (tail args)
    (flags { fFlag = getFlagValue args })
parseFlags ("-o":args) flags = parseFlags (tail args)
    (flags { oFLag = getFlagValue args })
parseFlags ("-e":args) flags = parseFlags (tail args)
    (flags { eFlag = getFlagValue args })
parseFlags (_:args) flags = parseFlags args flags

getFlagValue :: [String] -> Maybe String
getFlagValue [] = Nothing
getFlagValue (value:_) = Just value
