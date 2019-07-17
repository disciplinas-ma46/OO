class AddAttachmentAvatarToUsers < ActiveRecord::Migration[5.0]
    change_table :users do |t|
      t.attachment :avatar
    end

  def self.down
    remove_attachment :users, :avatar
  end
end
