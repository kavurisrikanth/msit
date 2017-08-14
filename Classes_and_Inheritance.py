# -*- coding: utf-8 -*-
"""
Created on Mon Aug 14 11:42:27 2017

@author: msit ksr

"""

"""
Uncomment for use in local machine:
import sys
sys.path.insert(0, 'I:\MSIT\IT\Week 3 - CSPP 1')
import common
"""

class Question:
    
    _class_qn_id = 0
    
    def __init__(self,
                 qn_text = '',
                 options = [],
                 correct_ans = '',
                 marks = 0):
        
#        nonlocal _class_qn_id
        self._qn_id = Question._class_qn_id
        Question._class_qn_id += 1
        
        self._qn_text = qn_text
        self._options = options
        self._correct_ans = correct_ans
        self._marks = marks
        
    @property
    def qn_id(self):
        return self._qn_id
        
        
    @property
    def qn_text(me):
        return me._qn_text
    
    @qn_text.setter
    def qn_text(self, text):
        self._qn_text = text
        
        
    @property
    def options(self):
        return self._options
    
    @options.setter
    def options(self, value):
        self._options = value
        
    
    @property
    def correct_ans(self):
        return self._correct_ans
    
    @correct_ans.setter
    def correct_ans(self, ans):
        self._correct_ans = ans
        
        
    @property
    def marks(self):
        return self._marks
    
    @marks.setter
    def marks(self, value):
        self._marks = value
        
    def __str__(self):
        ans = '\n'
        ans += ('Question #' + str(self.qn_id) + '\n')
        ans += (self.qn_text + '\n')
        for ind in range(1, 1 + len(self.options)):
            ans += (str(ind) + ': ' + str(self.options[ind - 1]) + '   ')
        ans += '\n'
        ans += ('Marks: ' + str(self.marks))

        return ans
        


class Quiz:
    
    def __init__(self, qns=[]):
        self.score = 0
        self.qList = qns
        self.response = {}
        
    def addQuestion(self, qn):
        self.qList.append(qn)
        
    def startQuiz(self):
#        qh = ()
        self.do_quiz()    
    
    def do_quiz(self):
        for qn in self.qList:
            
            valid = False
            while not valid:
                print(qn)
                if self.record_response(qn):
                    valid = True
                    if self.response[qn.qn_id] == qn.correct_ans:
                        self.score += qn.marks
                    
    
        return self.response
    
    def record_response(self, qn):
        ans = int(input('Enter answer: ').strip())
        if ans in qn.options:
            self.response[qn.qn_id] = ans
            return True
        else:
            print('Invalid response.')
            return False
        
    def showResult(self):
        print('\n\nResult')
        for ind in range(len(self.response)):
            print('Q #' + str(ind) + ': Response - ' + str(self.response[ind]) + \
                  ', Answer - ' + str(self.qList[ind].correct_ans))
        print('Score: ' + str(self.score))


def test():

#    qns = []
    quiz = Quiz()
    for i in range(3):
        qn = Question()
        qn.qn_text = 'Answer me this!'
        qn.options = [1, 2, 3, 4]
        qn.correct_ans = 4
        qn.marks = 10
#        print(qn.options)

        quiz.addQuestion(qn)
        
#        print(qn)
#        print(qn.qn_id)

    
    quiz.startQuiz()
    quiz.showResult()
    
test()