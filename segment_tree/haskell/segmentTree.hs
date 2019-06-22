data STNode a = Nil |
                Node { value :: a,
                       lnode :: STNode a,
                       rnode :: STNode a,
                       size  :: Int,
                       lb    :: Int,
                       rb    :: Int } deriving (Show)



leaf :: (Monoid a) => Int -> a -> STNode a
leaf n v = Node { value = v,
                  lnode = Nil,
                  rnode = Nil,
                  size  = 1,
                  lb    = n,
                  rb    = n } 


mergeNodes :: (Monoid a) => STNode a -> STNode a -> STNode a
mergeNodes ln rn = Node { value = (value ln) `mappend` (value rn),
                          lnode = ln,
                          rnode = rn,
                          size  = size ln + size rn,
                            lb    = lb ln,
                            rb    = rb rn } 


build :: (Monoid a) => Int -> STNode a  
build n = build' 0 (realN - 1)  where 
    realN = go n 1 where go n p = if p >= n then p else go n (p*2) 

    build' :: (Monoid a) => Int -> Int -> STNode a
    build' l r 
        | l == r    = leaf l mempty
        | otherwise = mergeNodes ln rn where 
            m = (l + r) `div` 2
            ln = build' l m
            rn = build' (m + 1) r


updateElement :: (Monoid a) => STNode a -> Int -> a -> STNode a
updateElement t i v 
    | lb t == rb t = t {value = v} 
    | otherwise    = mergeNodes nlnode nrnode where 
        m = (lb t + rb t) `div` 2 
        nlnode = if i <= m then updateElement (lnode t) i v else (lnode t) 
        nrnode = if i > m  then updateElement (rnode t) i v else (rnode t)


get :: (Monoid a) => STNode a -> Int -> Int -> a
get t l r 
    | lb t == l && rb t == r = value t
    | l > r        = mempty 
    | otherwise    = lvalue `mappend` rvalue where 
        m = (lb t + rb t) `div` 2 
        lvalue = get (lnode t) l (min l m)
        rvalue = get (rnode t) (max (m + 1) l) r



