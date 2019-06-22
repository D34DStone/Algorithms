data Queue a = Queue { l :: [a], r :: [a] } deriving (Show)

empty :: Queue a
empty = Queue [] []

isEmpty :: Queue a -> Bool
isEmpty (Queue l _) = null l

queue :: Queue a -> Queue a
queue (Queue l r) 
    | null l    = Queue (reverse r) []
    | otherwise = Queue l r

push :: Queue a -> a -> Queue a
push (Queue l r) v = Queue l (v : r)

pop :: Queue a -> (Maybe a, Queue a)
pop q@Queue { l = v : l, r = r } 
    | isEmpty q = (Nothing, q) 
    | otherwise = (Just v, queue $ Queue l r)
