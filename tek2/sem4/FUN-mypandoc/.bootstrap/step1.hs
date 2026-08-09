--
-- EPITECH PROJECT, 2024
-- B-FUN-400-BAR-4-1-mypandoc-jules.dufraiche
-- File description:
-- step1
--

import Control.Applicative (Alternative(..))

newtype Parser a = Parser {
  runParser :: String -> Maybe (a , String )
}

instance Functor Parser where
  fmap f p = Parser $ \str -> case runParser p str of
    Just (res, str1) -> Just (f res, str1)
    Nothing -> Nothing

instance Applicative Parser where
  pure v = Parser $ \str -> Just (v, str)
  p1 <*> p2 = Parser $ \str -> case runParser p1 str of
    Just (f, str1) -> case runParser p2 str1 of
      Just (res, str2) -> Just (f res, str2)
      Nothing -> Nothing
    Nothing -> Nothing

instance Alternative Parser where
  empty = Parser $ \_ -> Nothing
  p1 <|> p2 = Parser $ \str -> case runParser p1 str of
    Nothing -> runParser p2 str
    justRes -> justRes

parseChar :: Char -> Parser Char
parseChar c = Parser $ \str -> case str of
  (x:xs) | c == x -> Just (c, xs)
  _ -> Nothing

parseAnyChar :: String -> Parser Char
parseAnyChar chars = Parser $ \str -> case str of
  (x:xs) | x `elem` chars -> Just (x, xs)
  _ -> Nothing

parserOr :: Parser a -> Parser a -> Parser a
parserOr p1 p2 = Parser $ \str -> case runParser p1 str of
  Just res -> Just res
  Nothing -> runParser p2 str

parseAnd :: Parser a -> Parser b -> Parser (a, b)
parseAnd p1 p2 = Parser $ \str -> case runParser p1 str of
  Just (res1, str1) -> case runParser p2 str1 of
    Just (res2, str2) -> Just ((res1, res2), str2)
    Nothing -> Nothing
  Nothing -> Nothing

parseAndWith :: (a -> b -> c) -> Parser a -> Parser b -> Parser c
parseAndWith f p1 p2 = Parser $ \str -> case runParser p1 str of
  Just (res1, str1) -> case runParser p2 str1 of
    Just (res2, str2) -> Just (f res1 res2, str2)
    Nothing -> Nothing
  Nothing -> Nothing

parseMany :: Parser a -> Parser [a]
parseMany p = Parser $ \str -> case runParser p str of
  Just (res, str1) -> case runParser (parseMany p) str1 of
    Just (res1, str2) -> Just (res : res1, str2)
    Nothing -> Just ([res], str1)
  Nothing -> Just ([], str)

parseSome :: Parser a -> Parser [a]
parseSome p = (:) <$> p <*> parseMany p

parseUInt :: Parser Int --- parse an unsigned Int
parseUInt = Parser $ \str -> case runParser (parseSome (parseAnyChar ['0'..'9'])) str of
  Just (res, str1) -> Just (read res, str1)
  Nothing -> Nothing

parseInt :: Parser Int  --- parse a signed Int
parseInt = Parser $ \str -> case runParser (parseAnd (parseChar '-') parseUInt) str of
  Just ((_, res), str1) -> Just (-res, str1)
  Nothing -> runParser parseUInt str

parseTruple :: Parser (Int , Int , Int)
parseTruple = parseChar '(' * > parseInt <* parseChar ',' <* > parseInt <* parseChar
',' <* > parseInt <* parseChar ')'


parseTuple :: Parser a -> Parser (a, a) --- parse a tuple
parseTuple p = Parser $ \str -> case runParser (parseChar '(') str of
  Nothing -> Nothing
  Just (_, str1) -> case runParser p str1 of
    Nothing -> Nothing
    Just (res1, str2) -> case runParser (parseChar ',') str2 of
      Nothing -> Nothing
      Just (_, str3) -> case runParser p str3 of
        Nothing -> Nothing
        Just (res2, str4) -> case runParser (parseChar ')') str4 of
          Nothing -> Nothing
          Just (_, str5) -> Just ((res1, res2), str5)

parseTuple2 :: Parser a -> Parser (a, a)
parseTuple2 p = (,) <$> p <* parseChar ',' <*> p

-- main :: IO ()
-- main = do
--   print( "----PARSE CHAR----")
--   print( runParser (parseChar 'a') "abc")
--   print( "----PARSE ANY CHAR----")
--   print( runParser (parseAnyChar "bca") "abcd")
--   print("----PARSER OR----")
--   print( runParser (parserOr (parseChar 'a') (parseChar 'b')) "abcd")
--   print("----PARSER AND----")
--   print( runParser (parseAnd (parseChar 'a') (parseChar 'b')) "abcd")
--   print("----PARSER AND WITH----")
--   print( runParser (parseAndWith (\ x y -> [x,y]) (parseChar 'a') (parseChar 'b')) "abcd")
--   print("----PARSER MANY----")
--   print( runParser (parseMany (parseChar ' ')) "    foobar")
--   print("----PARSER SOME----")
--   print( runParser (parseSome (parseAnyChar ['0'..'9'])) "42foobar")
--   print("----PARSE INT TUPLE----")
--   print( runParser (parseTuple parseInt) "(123,456)foo bar")
--   print("----instance----")
--   print( runParser (fmap (+1) parseInt) "42")
--   print( runParser ((+1) <$> parseInt) "42")
--   print("----instance parsetuple2----")
--   print( runParser (parseInt <* parseChar 'f') "42foo")
--   print( runParser (parseInt *> parseChar 'b') "42bar")
--   print( runParser ((,) <$> parseInt <*> parseChar 'b') "42bar")
--   print("-----------------------------------------------------")
--   print( runParser parseJsonValue "null")
--   print( runParser parseJsonValue "true")
--   print( runParser parseJsonValue "42")
