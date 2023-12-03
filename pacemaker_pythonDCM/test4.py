import pickle

with open('usercred.pkl', "wb") as obj:
    pickle.dump(dict(), obj, pickle.HIGHEST_PROTOCOL)