# 1010. 总持续时间可被 60 整除的歌曲

用 map 保存 key 为 mod60 ，val 为歌曲数，遍历完一次歌曲后，再次遍历 map 即可，遍历 map 过程中计算的 key=a 后记得要同时删除 key=(60-a) 避免重复计算