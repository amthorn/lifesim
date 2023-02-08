# Lifesim

This project was something I've been working on just for fun. The premise of this project would assume stocks can be
predicted based on market trends, which is not necessarily true as stocks are affected by millions of factors outside
the representation of the historical values of the stock market. This is only going to be accurate within a
reasonable margin of error and may not be accurate at all.

## Execution

To run the genetic algorithm, run:

```
make build run LOG_LEVEL=INFO
```

Here is example output for GOOG stock over 100 generations with no genetic drift using default natural constants.

```
[INFO][4:28:47][lifesim/genetics/evolution.cc:17]: Generation 0 beginning.
[INFO][4:28:47][lifesim/genetics/evolution.cc:21]: Fittest is: 0.546326
[INFO][4:28:47][lifesim/genetics/evolution.cc:17]: Generation 1 beginning.
[INFO][4:28:47][lifesim/genetics/evolution.cc:21]: Fittest is: 0.553306
[INFO][4:28:47][lifesim/genetics/evolution.cc:17]: Generation 2 beginning.
[INFO][4:28:48][lifesim/genetics/evolution.cc:21]: Fittest is: 0.581224
[INFO][4:28:48][lifesim/genetics/evolution.cc:17]: Generation 3 beginning.
[INFO][4:28:48][lifesim/genetics/evolution.cc:21]: Fittest is: 0.574245
[INFO][4:28:48][lifesim/genetics/evolution.cc:17]: Generation 4 beginning.
[INFO][4:28:49][lifesim/genetics/evolution.cc:21]: Fittest is: 0.577495
[INFO][4:28:49][lifesim/genetics/evolution.cc:17]: Generation 5 beginning.
[INFO][4:28:49][lifesim/genetics/evolution.cc:21]: Fittest is: 0.584421
[INFO][4:28:49][lifesim/genetics/evolution.cc:17]: Generation 6 beginning.
[INFO][4:28:49][lifesim/genetics/evolution.cc:21]: Fittest is: 0.584421
[INFO][4:28:49][lifesim/genetics/evolution.cc:17]: Generation 7 beginning.
[INFO][4:28:50][lifesim/genetics/evolution.cc:21]: Fittest is: 0.581224
[INFO][4:28:50][lifesim/genetics/evolution.cc:17]: Generation 8 beginning.
[INFO][4:28:50][lifesim/genetics/evolution.cc:21]: Fittest is: 0.581224
[INFO][4:28:50][lifesim/genetics/evolution.cc:17]: Generation 9 beginning.
[INFO][4:28:50][lifesim/genetics/evolution.cc:21]: Fittest is: 0.581224
[INFO][4:28:50][lifesim/genetics/evolution.cc:17]: Generation 10 beginning.
[INFO][4:28:51][lifesim/genetics/evolution.cc:21]: Fittest is: 0.595184
[INFO][4:28:51][lifesim/genetics/evolution.cc:17]: Generation 11 beginning.
[INFO][4:28:51][lifesim/genetics/evolution.cc:21]: Fittest is: 0.587618
[INFO][4:28:51][lifesim/genetics/evolution.cc:17]: Generation 12 beginning.
[INFO][4:28:51][lifesim/genetics/evolution.cc:21]: Fittest is: 0.602163
[INFO][4:28:51][lifesim/genetics/evolution.cc:17]: Generation 13 beginning.
[INFO][4:28:52][lifesim/genetics/evolution.cc:21]: Fittest is: 0.628856
[INFO][4:28:52][lifesim/genetics/evolution.cc:17]: Generation 14 beginning.
[INFO][4:28:52][lifesim/genetics/evolution.cc:21]: Fittest is: 0.616122
[INFO][4:28:52][lifesim/genetics/evolution.cc:17]: Generation 15 beginning.
[INFO][4:28:52][lifesim/genetics/evolution.cc:21]: Fittest is: 0.609143
[INFO][4:28:52][lifesim/genetics/evolution.cc:17]: Generation 16 beginning.
[INFO][4:28:53][lifesim/genetics/evolution.cc:21]: Fittest is: 0.615110
[INFO][4:28:53][lifesim/genetics/evolution.cc:17]: Generation 17 beginning.
[INFO][4:28:53][lifesim/genetics/evolution.cc:21]: Fittest is: 0.621983
[INFO][4:28:53][lifesim/genetics/evolution.cc:17]: Generation 18 beginning.
[INFO][4:28:53][lifesim/genetics/evolution.cc:21]: Fittest is: 0.628856
[INFO][4:28:53][lifesim/genetics/evolution.cc:17]: Generation 19 beginning.
[INFO][4:28:54][lifesim/genetics/evolution.cc:21]: Fittest is: 0.628856
[INFO][4:28:54][lifesim/genetics/evolution.cc:17]: Generation 20 beginning.
[INFO][4:28:54][lifesim/genetics/evolution.cc:21]: Fittest is: 0.628856
[INFO][4:28:54][lifesim/genetics/evolution.cc:17]: Generation 21 beginning.
[INFO][4:28:54][lifesim/genetics/evolution.cc:21]: Fittest is: 0.621983
[INFO][4:28:54][lifesim/genetics/evolution.cc:17]: Generation 22 beginning.
[INFO][4:28:55][lifesim/genetics/evolution.cc:21]: Fittest is: 0.621983
[INFO][4:28:55][lifesim/genetics/evolution.cc:17]: Generation 23 beginning.
[INFO][4:28:55][lifesim/genetics/evolution.cc:21]: Fittest is: 0.628856
[INFO][4:28:55][lifesim/genetics/evolution.cc:17]: Generation 24 beginning.
[INFO][4:28:55][lifesim/genetics/evolution.cc:21]: Fittest is: 0.621983
[INFO][4:28:55][lifesim/genetics/evolution.cc:17]: Generation 25 beginning.
[INFO][4:28:56][lifesim/genetics/evolution.cc:21]: Fittest is: 0.635729
[INFO][4:28:56][lifesim/genetics/evolution.cc:17]: Generation 26 beginning.
[INFO][4:28:56][lifesim/genetics/evolution.cc:21]: Fittest is: 0.645373
[INFO][4:28:56][lifesim/genetics/evolution.cc:17]: Generation 27 beginning.
[INFO][4:28:57][lifesim/genetics/evolution.cc:21]: Fittest is: 0.649475
[INFO][4:28:57][lifesim/genetics/evolution.cc:17]: Generation 28 beginning.
[INFO][4:28:57][lifesim/genetics/evolution.cc:21]: Fittest is: 0.652192
[INFO][4:28:57][lifesim/genetics/evolution.cc:17]: Generation 29 beginning.
[INFO][4:28:57][lifesim/genetics/evolution.cc:21]: Fittest is: 0.645373
[INFO][4:28:57][lifesim/genetics/evolution.cc:17]: Generation 30 beginning.
[INFO][4:28:58][lifesim/genetics/evolution.cc:21]: Fittest is: 0.659012
[INFO][4:28:58][lifesim/genetics/evolution.cc:17]: Generation 31 beginning.
[INFO][4:28:58][lifesim/genetics/evolution.cc:21]: Fittest is: 0.659012
[INFO][4:28:58][lifesim/genetics/evolution.cc:17]: Generation 32 beginning.
[INFO][4:28:58][lifesim/genetics/evolution.cc:21]: Fittest is: 0.663221
[INFO][4:28:58][lifesim/genetics/evolution.cc:17]: Generation 33 beginning.
[INFO][4:28:59][lifesim/genetics/evolution.cc:21]: Fittest is: 0.659012
[INFO][4:28:59][lifesim/genetics/evolution.cc:17]: Generation 34 beginning.
[INFO][4:28:59][lifesim/genetics/evolution.cc:21]: Fittest is: 0.672652
[INFO][4:28:59][lifesim/genetics/evolution.cc:17]: Generation 35 beginning.
[INFO][4:28:59][lifesim/genetics/evolution.cc:21]: Fittest is: 0.679471
[INFO][4:28:59][lifesim/genetics/evolution.cc:17]: Generation 36 beginning.
[INFO][4:29:0][lifesim/genetics/evolution.cc:21]: Fittest is: 0.686291
[INFO][4:29:0][lifesim/genetics/evolution.cc:17]: Generation 37 beginning.
[INFO][4:29:0][lifesim/genetics/evolution.cc:21]: Fittest is: 0.686291
[INFO][4:29:0][lifesim/genetics/evolution.cc:17]: Generation 38 beginning.
[INFO][4:29:0][lifesim/genetics/evolution.cc:21]: Fittest is: 0.686291
[INFO][4:29:0][lifesim/genetics/evolution.cc:17]: Generation 39 beginning.
[INFO][4:29:1][lifesim/genetics/evolution.cc:21]: Fittest is: 0.699931
[INFO][4:29:1][lifesim/genetics/evolution.cc:17]: Generation 40 beginning.
[INFO][4:29:1][lifesim/genetics/evolution.cc:21]: Fittest is: 0.699931
[INFO][4:29:1][lifesim/genetics/evolution.cc:17]: Generation 41 beginning.
[INFO][4:29:1][lifesim/genetics/evolution.cc:21]: Fittest is: 0.693111
[INFO][4:29:1][lifesim/genetics/evolution.cc:17]: Generation 42 beginning.
[INFO][4:29:2][lifesim/genetics/evolution.cc:21]: Fittest is: 0.706750
[INFO][4:29:2][lifesim/genetics/evolution.cc:17]: Generation 43 beginning.
[INFO][4:29:2][lifesim/genetics/evolution.cc:21]: Fittest is: 0.699931
[INFO][4:29:2][lifesim/genetics/evolution.cc:17]: Generation 44 beginning.
[INFO][4:29:3][lifesim/genetics/evolution.cc:21]: Fittest is: 0.704459
[INFO][4:29:3][lifesim/genetics/evolution.cc:17]: Generation 45 beginning.
[INFO][4:29:3][lifesim/genetics/evolution.cc:21]: Fittest is: 0.706750
[INFO][4:29:3][lifesim/genetics/evolution.cc:17]: Generation 46 beginning.
[INFO][4:29:3][lifesim/genetics/evolution.cc:21]: Fittest is: 0.706750
[INFO][4:29:3][lifesim/genetics/evolution.cc:17]: Generation 47 beginning.
[INFO][4:29:4][lifesim/genetics/evolution.cc:21]: Fittest is: 0.706750
[INFO][4:29:4][lifesim/genetics/evolution.cc:17]: Generation 48 beginning.
[INFO][4:29:4][lifesim/genetics/evolution.cc:21]: Fittest is: 0.706750
[INFO][4:29:4][lifesim/genetics/evolution.cc:17]: Generation 49 beginning.
[INFO][4:29:4][lifesim/genetics/evolution.cc:21]: Fittest is: 0.720283
[INFO][4:29:4][lifesim/genetics/evolution.cc:17]: Generation 50 beginning.
[INFO][4:29:5][lifesim/genetics/evolution.cc:21]: Fittest is: 0.729341
[INFO][4:29:5][lifesim/genetics/evolution.cc:17]: Generation 51 beginning.
[INFO][4:29:5][lifesim/genetics/evolution.cc:21]: Fittest is: 0.722574
[INFO][4:29:5][lifesim/genetics/evolution.cc:17]: Generation 52 beginning.
[INFO][4:29:5][lifesim/genetics/evolution.cc:21]: Fittest is: 0.720283
[INFO][4:29:5][lifesim/genetics/evolution.cc:17]: Generation 53 beginning.
[INFO][4:29:6][lifesim/genetics/evolution.cc:21]: Fittest is: 0.722574
[INFO][4:29:6][lifesim/genetics/evolution.cc:17]: Generation 54 beginning.
[INFO][4:29:6][lifesim/genetics/evolution.cc:21]: Fittest is: 0.729341
[INFO][4:29:6][lifesim/genetics/evolution.cc:17]: Generation 55 beginning.
[INFO][4:29:6][lifesim/genetics/evolution.cc:21]: Fittest is: 0.729341
[INFO][4:29:6][lifesim/genetics/evolution.cc:17]: Generation 56 beginning.
[INFO][4:29:7][lifesim/genetics/evolution.cc:21]: Fittest is: 0.736107
[INFO][4:29:7][lifesim/genetics/evolution.cc:17]: Generation 57 beginning.
[INFO][4:29:7][lifesim/genetics/evolution.cc:21]: Fittest is: 0.729341
[INFO][4:29:7][lifesim/genetics/evolution.cc:17]: Generation 58 beginning.
[INFO][4:29:7][lifesim/genetics/evolution.cc:21]: Fittest is: 0.729341
[INFO][4:29:7][lifesim/genetics/evolution.cc:17]: Generation 59 beginning.
[INFO][4:29:8][lifesim/genetics/evolution.cc:21]: Fittest is: 0.729341
[INFO][4:29:8][lifesim/genetics/evolution.cc:17]: Generation 60 beginning.
[INFO][4:29:8][lifesim/genetics/evolution.cc:21]: Fittest is: 0.736107
[INFO][4:29:8][lifesim/genetics/evolution.cc:17]: Generation 61 beginning.
[INFO][4:29:9][lifesim/genetics/evolution.cc:21]: Fittest is: 0.736107
[INFO][4:29:9][lifesim/genetics/evolution.cc:17]: Generation 62 beginning.
[INFO][4:29:9][lifesim/genetics/evolution.cc:21]: Fittest is: 0.742874
[INFO][4:29:9][lifesim/genetics/evolution.cc:17]: Generation 63 beginning.
[INFO][4:29:9][lifesim/genetics/evolution.cc:21]: Fittest is: 0.736107
[INFO][4:29:9][lifesim/genetics/evolution.cc:17]: Generation 64 beginning.
[INFO][4:29:10][lifesim/genetics/evolution.cc:21]: Fittest is: 0.736107
[INFO][4:29:10][lifesim/genetics/evolution.cc:17]: Generation 65 beginning.
[INFO][4:29:10][lifesim/genetics/evolution.cc:21]: Fittest is: 0.742874
[INFO][4:29:10][lifesim/genetics/evolution.cc:17]: Generation 66 beginning.
[INFO][4:29:10][lifesim/genetics/evolution.cc:21]: Fittest is: 0.736107
[INFO][4:29:10][lifesim/genetics/evolution.cc:17]: Generation 67 beginning.
[INFO][4:29:11][lifesim/genetics/evolution.cc:21]: Fittest is: 0.749640
[INFO][4:29:11][lifesim/genetics/evolution.cc:17]: Generation 68 beginning.
[INFO][4:29:11][lifesim/genetics/evolution.cc:21]: Fittest is: 0.749640
[INFO][4:29:11][lifesim/genetics/evolution.cc:17]: Generation 69 beginning.
[INFO][4:29:11][lifesim/genetics/evolution.cc:21]: Fittest is: 0.742874
[INFO][4:29:11][lifesim/genetics/evolution.cc:17]: Generation 70 beginning.
[INFO][4:29:12][lifesim/genetics/evolution.cc:21]: Fittest is: 0.756407
[INFO][4:29:12][lifesim/genetics/evolution.cc:17]: Generation 71 beginning.
[INFO][4:29:12][lifesim/genetics/evolution.cc:21]: Fittest is: 0.763173
[INFO][4:29:12][lifesim/genetics/evolution.cc:17]: Generation 72 beginning.
[INFO][4:29:12][lifesim/genetics/evolution.cc:21]: Fittest is: 0.756407
[INFO][4:29:12][lifesim/genetics/evolution.cc:17]: Generation 73 beginning.
[INFO][4:29:13][lifesim/genetics/evolution.cc:21]: Fittest is: 0.756407
[INFO][4:29:13][lifesim/genetics/evolution.cc:17]: Generation 74 beginning.
[INFO][4:29:13][lifesim/genetics/evolution.cc:21]: Fittest is: 0.763173
[INFO][4:29:13][lifesim/genetics/evolution.cc:17]: Generation 75 beginning.
[INFO][4:29:14][lifesim/genetics/evolution.cc:21]: Fittest is: 0.763173
[INFO][4:29:14][lifesim/genetics/evolution.cc:17]: Generation 76 beginning.
[INFO][4:29:14][lifesim/genetics/evolution.cc:21]: Fittest is: 0.766903
[INFO][4:29:14][lifesim/genetics/evolution.cc:17]: Generation 77 beginning.
[INFO][4:29:15][lifesim/genetics/evolution.cc:21]: Fittest is: 0.773563
[INFO][4:29:15][lifesim/genetics/evolution.cc:17]: Generation 78 beginning.
[INFO][4:29:15][lifesim/genetics/evolution.cc:21]: Fittest is: 0.766903
[INFO][4:29:15][lifesim/genetics/evolution.cc:17]: Generation 79 beginning.
[INFO][4:29:15][lifesim/genetics/evolution.cc:21]: Fittest is: 0.766903
[INFO][4:29:15][lifesim/genetics/evolution.cc:17]: Generation 80 beginning.
[INFO][4:29:16][lifesim/genetics/evolution.cc:21]: Fittest is: 0.786883
[INFO][4:29:16][lifesim/genetics/evolution.cc:17]: Generation 81 beginning.
[INFO][4:29:16][lifesim/genetics/evolution.cc:21]: Fittest is: 0.773563
[INFO][4:29:16][lifesim/genetics/evolution.cc:17]: Generation 82 beginning.
[INFO][4:29:17][lifesim/genetics/evolution.cc:21]: Fittest is: 0.786883
[INFO][4:29:17][lifesim/genetics/evolution.cc:17]: Generation 83 beginning.
[INFO][4:29:17][lifesim/genetics/evolution.cc:21]: Fittest is: 0.773563
[INFO][4:29:17][lifesim/genetics/evolution.cc:17]: Generation 84 beginning.
[INFO][4:29:17][lifesim/genetics/evolution.cc:21]: Fittest is: 0.766903
[INFO][4:29:17][lifesim/genetics/evolution.cc:17]: Generation 85 beginning.
[INFO][4:29:18][lifesim/genetics/evolution.cc:21]: Fittest is: 0.773563
[INFO][4:29:18][lifesim/genetics/evolution.cc:17]: Generation 86 beginning.
[INFO][4:29:18][lifesim/genetics/evolution.cc:21]: Fittest is: 0.780223
[INFO][4:29:18][lifesim/genetics/evolution.cc:17]: Generation 87 beginning.
[INFO][4:29:18][lifesim/genetics/evolution.cc:21]: Fittest is: 0.773563
[INFO][4:29:18][lifesim/genetics/evolution.cc:17]: Generation 88 beginning.
[INFO][4:29:19][lifesim/genetics/evolution.cc:21]: Fittest is: 0.773563
[INFO][4:29:19][lifesim/genetics/evolution.cc:17]: Generation 89 beginning.
[INFO][4:29:19][lifesim/genetics/evolution.cc:21]: Fittest is: 0.773563
[INFO][4:29:19][lifesim/genetics/evolution.cc:17]: Generation 90 beginning.
[INFO][4:29:20][lifesim/genetics/evolution.cc:21]: Fittest is: 0.773563
[INFO][4:29:20][lifesim/genetics/evolution.cc:17]: Generation 91 beginning.
[INFO][4:29:20][lifesim/genetics/evolution.cc:21]: Fittest is: 0.773563
[INFO][4:29:20][lifesim/genetics/evolution.cc:17]: Generation 92 beginning.
[INFO][4:29:20][lifesim/genetics/evolution.cc:21]: Fittest is: 0.786883
[INFO][4:29:20][lifesim/genetics/evolution.cc:17]: Generation 93 beginning.
[INFO][4:29:21][lifesim/genetics/evolution.cc:21]: Fittest is: 0.793543
[INFO][4:29:21][lifesim/genetics/evolution.cc:17]: Generation 94 beginning.
[INFO][4:29:21][lifesim/genetics/evolution.cc:21]: Fittest is: 0.786883
[INFO][4:29:21][lifesim/genetics/evolution.cc:17]: Generation 95 beginning.
[INFO][4:29:22][lifesim/genetics/evolution.cc:21]: Fittest is: 0.786883
[INFO][4:29:22][lifesim/genetics/evolution.cc:17]: Generation 96 beginning.
[INFO][4:29:22][lifesim/genetics/evolution.cc:21]: Fittest is: 0.786883
[INFO][4:29:22][lifesim/genetics/evolution.cc:17]: Generation 97 beginning.
[INFO][4:29:22][lifesim/genetics/evolution.cc:21]: Fittest is: 0.791997
[INFO][4:29:22][lifesim/genetics/evolution.cc:17]: Generation 98 beginning.
[INFO][4:29:23][lifesim/genetics/evolution.cc:21]: Fittest is: 0.791997
[INFO][4:29:23][lifesim/genetics/evolution.cc:17]: Generation 99 beginning.
[INFO][4:29:23][lifesim/genetics/evolution.cc:21]: Fittest is: 0.791997
[INFO][4:29:23][lifesim/genetics/evolution.cc:25]: Evolution Complete.
[INFO][4:29:23][lifesim/genetics/evolution.cc:26]: Percentage Correct: 76.642336%
[INFO][4:29:23][lifesim/genetics/evolution.cc:27]: Longest Segment: 15/147
[INFO][4:29:23][lifesim/genetics/evolution.cc:28]: Prediction: 227694.027408 (stock will go up)
```

Observe from the above simulation that each generation does improve on the predictive capability of the model.
However, it can never reach 100% as each prediction is only based on historical trends.

Confidence intervals are only to be interpretted within that context.

Each generation takes about 1/3 of a second.
