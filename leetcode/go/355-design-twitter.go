package leetcode

type Tweet struct {
	ID     int
	UserID int
}

type Twitter struct {
	Tweets  []*Tweet                 // 保存所有tweets
	Follows map[int]map[int]struct{} // 保存folloe关系，key是follower，value是followee set
}

/** Initialize your data structure here. */
func Constructor() Twitter {
	return Twitter{
		Tweets:  make([]*Tweet, 0),
		Follows: make(map[int]map[int]struct{}),
	}
}

/** Compose a new tweet. */
func (this *Twitter) PostTweet(userId int, tweetId int) {
	this.Tweets = append(this.Tweets, &Tweet{
		ID:     tweetId,
		UserID: userId,
	})
}

/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
func (this *Twitter) GetNewsFeed(userId int) []int {
	res := []int{}
	followees := this.Follows[userId]
	for i := len(this.Tweets) - 1; i >= 0; i-- {
		if len(res) == 10 {
			break
		}
		t := this.Tweets[i]
		if t.UserID == userId {
			res = append(res, t.ID)
			continue
		}
		if _, ok := followees[t.UserID]; ok {
			res = append(res, t.ID)
		}
	}
	return res
}

/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
func (this *Twitter) Follow(followerId int, followeeId int) {
	f, ok := this.Follows[followerId]
	if !ok {
		this.Follows[followerId] = map[int]struct{}{followeeId: {}}
	} else {
		f[followeeId] = struct{}{}
	}
}

/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
func (this *Twitter) Unfollow(followerId int, followeeId int) {
	f, ok := this.Follows[followerId]
	if ok {
		delete(f, followeeId)
	}
}

/**
 * Your Twitter object will be instantiated and called as such:
 * obj := Constructor();
 * obj.PostTweet(userId,tweetId);
 * param_2 := obj.GetNewsFeed(userId);
 * obj.Follow(followerId,followeeId);
 * obj.Unfollow(followerId,followeeId);
 */
