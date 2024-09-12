from wxauto import WeChat
wx= WeChat()
msg = "[便便]"
who1 = ""
wx.SendMsg(msg=msg,who=who1)
wx.AddListenChat(who1)
# wait = 0.1
while True:
    msgs = wx.GetListenMessage()
    for chat in msgs:
        who = chat.who 
        one_msgs = msgs.get(chat) 
        for msg in one_msgs:
            # msgtype = msg.type 
            content = msg.content 
            print(f'【{who}】：{content}')
            if content == '[Bomb]':
                chat.SendMsg('[Poop]')
