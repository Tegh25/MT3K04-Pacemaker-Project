import pickle

# with open("userpref.pkl", 'rb') as pkl:
#     pref = pickle.load(pkl)
# print(pref)
# for key in pref:
#     del pref[key]["presets"]["_temp"]
# print(pref)
pref = {'db49b86420995fd50561e44ca97f9cff0f67798f182119c42984fd1002155a57':
    {'loginname': 'Forbesii Du', 'lang_var_str': 'ZH_HK', 'lang': 'langpack.CN',
     'presets': {
         'test1': ['AOO', '60', '120', '3.5', '0.4'], 
         'test2': ['AOOR', '60', '120', '3.5', '0.4', '_Med', '30', '8', '5'],
         'test3': ['VOO', '60', '120', '3.5', '0.4']}}}
with open("userpref.pkl", 'wb') as pkl:
    pickle.dump(pref, pkl, protocol=pickle.HIGHEST_PROTOCOL)