//
//  DataManager.swift
//  Raccoon
//
//  Created by stajer on 04.05.2021.
//

import Foundation

struct Post: Codable {
    
    var userId: Int
    var id: Int
    var title: String
    var body: String
    
}

class NetworkDataManager {
    
    private var postArray: [Post] = []
        
    private func parseData(data: Data) -> [Post] {
        let decoder = JSONDecoder()
        do {
            postArray = try decoder.decode([Post].self, from: data)
        }
        catch {
            print("JSON error: \(error.localizedDescription)")
        }
        return postArray
    }
}

extension NetworkDataManager: DataManager {
    
    func getStringValue(at index: Int) -> String {
        return postArray[index].title
    }
    
    func getDataCount() -> Int{
        return postArray.count
    }
 
    func removeValue(at index: Int) {
        postArray.remove(at: index)
    }
    
    func insertValue<T>(_ value: T, at index: Int) {
        guard let stringValue = value as? String else {
            return
        }
        postArray.insert(Post(userId: 0, id: 0, title: stringValue, body: ""), at: 0)
    }
    
    func updateValue<T>(for value: T, at index: Int) {
        guard let stringValue = value as? String else {
            return
        }
        postArray[index].title = stringValue
    }
    
    func loadData(_ completion: @escaping () -> Void) {
        let url = URL(string: "https://jsonplaceholder.typicode.com/posts")!
        let task = URLSession.shared.dataTask(with:url) { [weak self]
            (data, response, error) in
            if let error = error {
                print("Error occured: \(error.localizedDescription)")
                completion()
                return
            }
            guard let httpResponse = response as? HTTPURLResponse,
                (200...299).contains(httpResponse.statusCode) else {
                completion()
                return
            }
            guard let self = self,
                  let data = data else {
                completion()
                return
            }
            self.postArray = self.parseData(data: data)
            completion()
        }
        task.resume()
    }
    
}
