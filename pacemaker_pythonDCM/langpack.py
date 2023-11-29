class ADict(dict):
    def __getitem__(self, __key: str):
        try:
            float(__key)
            return __key
        except:
            if "rev" in __key:
                __key = __key[3:]
                try:
                    float(__key)
                    return __key
                except:
                    for key, val in super().items():
                        if __key == val:
                                return key
            return super().__getitem__(__key)

EN = ADict({
    "RootTitle<": "Sign in as ",
    "RootTitle>": "",
    "SelPort"   : "Select a serial port:",
    "SerialConn": "Connected",
    "SerlDiscon": "Disconnect",
    "Logout"    : "Logout",
    "Settings"  : "Settings",
    "ShowEgram" : "Show Electrogram",
    "HideEgram" : "Hide Electrogram",
    "Presets"   : "Presets",
    "SelPreset" : "Select or add a preset",
    "PacePara"  : "Pacemaker Parameters",
    "SelPaceMod": "Pacing mode",
    "Back"      : "Back",
    "Yes"       : "Yes",
    "No"        : "Cancel",
    "LdCnfrmTtl": "Confirm Load",
    "LdCnfrmTxt": "Loading the preset would override the current settings. Continue?",
    "DelCfrmTtl": "Confirm delete",
    "DelCfrmTxt": "Will delete this preset. Continue?",
    "NoValInTtl": "Not a valid input",
    "NoValInMsg": "The name you've input is invalid, please try again!",
    "PsetExist" : "Name Exist",
    "PsExstMsg" : "The name is already exist!",
    "NoModeSel" : "Select a mode",
    "NoModMsg"  : "Please select a mode and try again!",
    "NewPreset" : "New Preset",
    "AskPrsetNm": "New preset name: ",
    "Vent"      : "Ventricular",
    "Atr"       : "Atrium",
    "LowRtLim"  : "Lower Rate Limit (ppm)",
    "UppRtLim"  : "Upper Rate Limit (ppm)",
    "VAmp"      : "Ventricular Amplitude (V)",
    "AAmp"      : "Atrium Amplitude (V)",
    "APulseWid" : "Atrium Pulse Width (ms)",
    "VPulseWid" : "Ventricular Pulse Width (ms)",
    "ASensi"    : "Atrium Sensitivity (mV)",
    "VSensi"    : "Ventricular Sensitivity (mV)",
    "ARefrctPrd": "Atrium Refractory Period (ms)",
    "VRefrctPrd": "Ventricular Refractory Period (ms)",
    "PVARP"     : "PVARP (ms)",
    "Hysteresis": "Hysterisis (ppm)",
    "RateSmooth": "Rate Smoothing",
    "ActivThold": "Activity Threshold",
    "ReactTime" : "React Time (s)",
    "RespFactor": "Response Factor",
    "RecovTime" : "Recovery Time (min)",
    "_OFF"      : "OFF",
    "_V-Low"    : "Very Low",
    "_Low"      : "Low",
    "_Med-Low"  : "Mid Low",
    "_Med"      : "Mid",
    "_Med-High" : "Mid High",
    "_High"     : "High",
    "_V-High"   : "Very High"
})

CN = ADict({
    "RootTitle<": "以 ",
    "RootTitle>": " 登入",
    "SelPort"   : "選擇一個序列埠：",
    "SerialConn": "已連線",
    "SerlDiscon": "未連線",
    "Logout"    : "登出",
    "Settings"  : "設定",
    "ShowEgram" : "顯示心電圖",
    "HideEgram" : "隱藏心電圖",
    "Presets"   : "預設配置",
    "SelPreset" : "選取或新增預設",
    "PacePara"  : "心律調節器變數",
    "SelPaceMod": "調節器模式",
    "Back"      : "返回",
    "Yes"       : "確定",
    "No"        : "取消",
    "LdCnfrmTtl": "確認加載",
    "LdCnfrmTxt": "加載預設將會覆蓋當前設定，繼續？",
    "DelCfrmTtl": "確認刪除",
    "DelCfrmTxt": "將會刪除此預設，繼續？",
    "NoValInTtl": "輸入無效",
    "NoValInMsg": "輸入的名稱無效，請再試。",
    "PsetExist" : "預設名稱存在",
    "PsExstMsg" : "預設名稱已存在，請再試。",
    "NoModeSel" : "請選擇一個模式",
    "NoModMsg"  : "請選擇一個模式後再試！",
    "NewPreset" : "新預設",
    "AskPrsetNm": "新預設名稱：",
    "Vent"      : "心室",
    "Atr"       : "心房",
    "LowRtLim"  : "最低心律（次每分鐘）",
    "UppRtLim"  : "最高心律（次每分鐘）",
    "VAmp"      : "心室振幅（伏）",
    "AAmp"      : "心房振幅（伏）",
    "APulseWid" : "心房脈衝寬度（毫秒）",
    "VPulseWid" : "心室脈衝寬度（毫秒）",
    "ASensi"    : "心房靈敏度（毫伏）",
    "VSensi"    : "心室靈敏度（毫伏）",
    "ARefrctPrd": "心房不應期（毫秒）",
    "VRefrctPrd": "心室不應期（毫秒）",
    "PVARP"     : "PVARP（毫秒）",
    "Hysteresis": "遲滯（次每分鐘）",
    "RateSmooth": "平滑",
    "ActivThold": "活動閾值",
    "ReactTime" : "響應時間（秒）",
    "RespFactor": "回應係數",
    "RecovTime" : "恢復時間（分）",
    "_OFF"      : "關",
    "_V-Low"    : "極低",
    "_Low"      : "低",
    "_Med-Low"  : "中低",
    "_Med"      : "中",
    "_Med-High" : "中高",
    "_High"     : "高",
    "_V-High"   : "極高"
})

FR = {
    "RootTitle<": "Connectez-vous en tant que ",
    "RootTitle>": "",
    "SelPort"   : "Sélectionner un port série",
    "SerialConn": "Connecté",
    "SerlDiscon": "Débranché",
    "Logout"    : "Déconnexion",
    "Settings"  : "Paramètres",

    "ShowEgram" : "Afficher Électrogramme",
    "HideEgram" : "Cacher Électrogramme",
    "Presets"   : "Préréglages",
    "SelPreset" : "Select or add a preset",
    "PacePara"  : "Pacemaker Parameters",
    "SelPaceMod": "Pacing mode",
    "Back"      : "Back",
    "Yes"       : "Yes",
    "No"        : "Cancel",
    "LdCnfrmTtl": "Confirm Load",
    "LdCnfrmTxt": "Le chargement du préréglage remplace les paramètres actuels. Continuer?",
    "DelCfrmTtl": "Confirm delete",
    "DelCfrmTxt": "Supprime ce préréglage. Poursuivre?",
    "NoValInTtl": "Not a valid input",
    "NoValInMsg": "The name you've input is invalid, please try again!",
    "PsetExist" : "Name Exist",
    "PsExstMsg" : "The name is already exist!",
    "NoModeSel" : "Select a mode",
    "NoModMsg"  : "Please select a mode and try again!",
    "NewPreset" : "New Preset",
    "AskPrsetNm": "New preset name: ",
    "Vent"      : "Ventricular",
    "Atr"       : "Atrium",
    "LowRtLim"  : "Lower Rate Limit (ppm)",
    "UppRtLim"  : "Upper Rate Limit (ppm)",
    "VAmp"      : "Ventricular Amplitude (V)",
    "AAmp"      : "Atrium Amplitude (V)",
    "APulseWid" : "Atrium Pulse Width (ms)",
    "VPulseWid" : "Ventricular Pulse Width (ms)",
    "ASensi"    : "Atrium Sensitivity (mV)",
    "VSensi"    : "Ventricular Sensitivity (mV)",
    "ARefrctPrd": "Atrium Refractory Period (ms)",
    "VRefrctPrd": "Ventricular Refractory Period (ms)",
    "PVARP"     : "PVARP (ms)",
    "Hysteresis": "Hysterisis (ppm)",
    "RateSmooth": "Rate Smoothing",
    "ActivThold": "Activity Threshold",
    "ReactTime" : "React Time (s)",
    "RespFactor": "Response Factor",
    "RecovTime" : "Recovery Time (min)",
    "_OFF"      : "OFF",
    "_V-Low"    : "Very Low",
    "_Low"      : "Low",
    "_Med-Low"  : "Mid Low",
    "_Med"      : "Mid",
    "_Med-High" : "Mid High",
    "_High"     : "High",
    "_V-High"   : "Very High"
}