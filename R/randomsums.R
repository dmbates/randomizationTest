randomsums <- function(vals, nsamp, k) {
    stopifnot(is.integer(vals), 0L < k, k < length(vals), 0L < nsamp)
    .Call("sampleSums",vals,as.integer(nsamp),as.integer(k),package="randomizationTest")
}

