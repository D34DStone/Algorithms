data Stack a = Stack [a] deriving Show

empty :: Stack a -> Bool
empty (Stack a) = null a

push :: Stack a -> a -> Stack a
push (Stack as) a = Stack (a : as)

pop :: Stack a -> (Maybe a, Stack a)
pop (Stack []) = (Nothing, Stack []) 
pop (Stack (a : as)) = (Just a, Stack as)
