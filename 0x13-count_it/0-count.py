#!/usr/bin/python3
"""
0. Count it!
"""
import requests


def count_words(subreddit, word_list, after='', word_count={}):
    """
    A recursive function that queries the Reddit API, parses the title of
    all hot articles, and prints a sorted count of given keywords
    """

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {'User-Agent': 'gnnr___'}
    params = {'limit': '100', 'after': after}
    res = requests.get(url, headers=headers,
                       params=params, allow_redirects=False)
    if res.status_code == 200:
        data = res.json().get('data')
        after = data.get('after')
        children = data.get('children')
        titles = [child.get('data').get('title') for child in children]
        for i in range(len(titles)):
            titles[i] = titles[i].lower().split()
        for title in titles:
            for word in word_list:
                count = title.count(word)
                if word in word_count:
                    word_count[word] += count
                else:
                    word_count[word] = count

        if after is not None:
            return count_words(subreddit, word_list, after, word_count)
        else:
            if not len(word_count) > 0:
                return
            sorted_data = sorted(word_count.items(),
                                 key=lambda key_value: (-key_value[1],
                                                        key_value[0]))
            for k, v in sorted_data:
                print('{}: {}'.format(k, v))
    else:
        return
