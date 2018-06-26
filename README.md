# 动态页面置换算法模拟器
在开发之初，我想过是否应该用GUI来展现置换算法的过程。后来考虑到单纯的DOS界面受限于各种因素，不能很直观地表现置换的过程，而只能提供一个结果，算是一个“遗憾”，所以我开始构思利用GUI来动态单步地展现算法执行的过程。在明确了要求之后，发现其实业务逻辑比较简单，所以主要的难点在于GUI界面的设计以及跟数据流的结合。于是我将业务逻辑主要放在一个类里，然后提供出接口来给GUI显示数据用，同时由于生成随机数需要几个参数（页的大小，缓存页的容量），所以写了接口接收GUI传来的数据流。做好了这样的简单设计之后，可以专注于GUI的设计了。受到课本上描述LRU算法时采用栈图的形式的启发，于是想到将用户的缓存表打印出来，同时为了体现中断，把序列的前，中，后三个序号也都显示出来，这样就可以直观地观察当前的中断情况。而中断率实时显示，也可以更好地体会整个过程中置换的频繁性。
![未初始化界面](https://github.com/SCNUJackyChen/Dramatic-Simulator-of-Operating-System-Algorithm/raw/master/image/uninit.png)
![运行界面](https://github.com/SCNUJackyChen/Dramatic-Simulator-of-Operating-System-Algorithm/raw/master/image/running.png)
![查看地址](https://github.com/SCNUJackyChen/Dramatic-Simulator-of-Operating-System-Algorithm/raw/master/image/showaddress.png)
![查看页号](https://github.com/SCNUJackyChen/Dramatic-Simulator-of-Operating-System-Algorithm/raw/master/image/showpages.png)
![设计流程图](https://github.com/SCNUJackyChen/Dramatic-Simulator-of-Operating-System-Algorithm/raw/master/image/designflowchart.png)

