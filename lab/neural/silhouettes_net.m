dataURL = 'https://people.cs.umass.edu/~marlin/data/caltech101_silhouettes_28.mat';
filename = 'caltech101_silhouettes_28.mat';
outfilename = websave(filename, dataURL);
data = load(outfilename);