import gym
import numpy as np 

def run_episode(env,parameters):
    observation = env.reset()
    totalreward = 0
    for _ in range(200):
        action = 0 if np.matmul(parameters, observation) < 0 else 1
        observation, reward, done, info = env.step(action)
        totalreward += reward
        if done:
            break
    env.render()
    return totalreward

def train():
    env = gym.make('CartPole-v0')
    bestreward = 0
    bestparams = None
    counter = 0
    
    for _ in range(100):
        parameters = np.random.rand(4) * 2 - 1
        counter+=1
        reward = run_episode(env, parameters)
        print("Episode %d :"%(_))
        print('reward: '+str(reward))
        print(parameters)
        if reward > bestreward:
            bestreward = reward
            bestparams = parameters
            if reward == 200:
                break

    return counter

train()